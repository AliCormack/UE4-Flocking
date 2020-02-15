
#include "BoidController.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Core/Public/Async/ParallelFor.h"

TArray<FVector> ABoidController::RaycastVectors;

ABoidController::ABoidController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	HierarchicalInstancedStaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(this, TEXT("HierarchicalInstancedStaticMeshComponent"));
	RootComponent = HierarchicalInstancedStaticMeshComponent;

	PrimaryActorTick.bCanEverTick = true;	
}

void ABoidController::CalculateRaycastVectors()
{
	float goldenRatio = (1 + FMath::Sqrt(5)) / 2;
	float angleIncrement = UKismetMathLibrary::GetPI() * 2 * goldenRatio;

	for (int i = 0; i < NumRaycastVectors; i++)
	{
		float t = (float)i / NumRaycastVectors;
		float inclination = FMath::Acos(1 - 2 * t);
		float azimuth = angleIncrement * i;

		float x = FMath::Sin(inclination) * FMath::Cos(azimuth);
		float y = FMath::Sin(inclination) * FMath::Sin(azimuth);
		float z = FMath::Cos(inclination);
		auto Point = FVector(x, y, z);
		
		RaycastVectors.Add(Point);

		// Debug
		/*
		auto Col = 255.0f * t;
		auto PointColor = FColor(Col, Col, Col);
		DrawDebugPoint(GetWorld(), Point, 10, PointColor, true, 9999999.0f);*/
	}	
}

void ABoidController::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < NumBoids; i++)
	{
		CreateBoid();
	}

	BoidsOrigin = GetActorLocation();

	CalculateRaycastVectors();
}

FVector ABoidController::GetRandomSpawnLocation() const
{
	return BoidsOrigin + UKismetMathLibrary::RandomUnitVector() * UKismetMathLibrary::RandomFloat() * SpawnRadius;
}

void ABoidController::CreateBoid()
{
	auto Transform = UKismetMathLibrary::MakeTransform(
		GetRandomSpawnLocation(),
		FRotator::ZeroRotator,
		BoidScale// *(UKismetMathLibrary::RandomFloat() / 0.5 + 0.5) // TODO make scale randomness a parameter
	);

	int HierarchicalMeshIndex = HierarchicalInstancedStaticMeshComponent->AddInstance(Transform);

	float RandMaxVelocity = MininmumMaxVelocity + UKismetMathLibrary::RandomFloat() * (MaximumMaxVelocity - MininmumMaxVelocity);

	auto BoidData = FBoidData
	{
		Transform,
		UKismetMathLibrary::RandomUnitVector() * (UKismetMathLibrary::RandomFloat() * 2 - 1) * RandMaxVelocity,
		FVector::ZeroVector,
		RandMaxVelocity,
		HierarchicalMeshIndex
	};

	BoidDatas.Add(BoidData);	
}

void ABoidController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Iterate over last frame data to prevent cascaded updates
	const TArray<FBoidData> LastFrameData = BoidDatas;

	ParallelFor(BoidDatas.Num(), [&](int32 i)
	{
		const bool bProcessForces = true;

		auto& TargetBoidData = BoidDatas[i];

		if (bProcessForces)
		{
			const auto TargetLocation = TargetBoidData.Transform.GetLocation();

			TargetBoidData.NumNeighbours = 0;

			auto AlignmentForce = FVector::ZeroVector;
			auto CohesionForce = FVector::ZeroVector;

			int SeperationNeighbourCount = 0;
			auto SeperationForce = FVector::ZeroVector;

			auto SeekForce = FVector::ZeroVector;

			auto CollisionAvoidanceForce = FVector::ZeroVector;

			auto ViewForce = FVector::ZeroVector;

			for (int j = 0; j < LastFrameData.Num(); j++)
			{
				const auto& OtherBoidData = LastFrameData[j];

				// Skip if self
				if (OtherBoidData.InstancedMeshIndex == TargetBoidData.InstancedMeshIndex)
					continue;

				const auto OtherLocation = OtherBoidData.Transform.GetLocation();
				const auto Difference = OtherLocation - TargetLocation;
				const auto Distance = Difference.Size();

				if (Distance < NeighbourRadius && Distance > 0)
				{
					// Seperation
					if (Distance < SeperationRadius)
					{
						SeperationNeighbourCount++;
						SeperationForce -= Difference;
					}

					// Don't need to calculate other forces if we need to seperate from other agents
					if (SeperationForce.Size() == 0)
					{
						// If in view cone			
						float degreesOut = FVector::DotProduct(TargetBoidData.Velocity, Difference);
						degreesOut /= Distance;
						degreesOut /= TargetBoidData.Velocity.Size();
						if (degreesOut >= cos(FMath::DegreesToRadians(VisionConeAngle / 2.0f)))
						{
							CohesionForce += OtherLocation;
							AlignmentForce += OtherBoidData.Velocity;

							TargetBoidData.NumNeighbours++;



							if (ViewForce.Size() == 0)
							{
								FVector Right = FVector::CrossProduct(Difference, TargetBoidData.Velocity);

								/*if (TargetBoidData.InstancedMeshIndex == DebugIndex+1 && bShowDebug)
								{
									DrawDebugLine()
								}*/
							}


							if (TargetBoidData.NumNeighbours >= MaxNeighbours)
								break;
						}
					}
				}
			}

			// Collision
			CollisionAvoidanceForce = FindUnobstructedDirection(TargetBoidData);

			// Seek
			const auto SeekLocation = SeekTransform.GetLocation();
			const auto SeekDifference = SeekLocation - TargetLocation;
			const auto SeekDistance = SeekDifference.Size();

			if (SeekDistance > SeekStopRadius)
				SeekForce = SeekDifference;

			if (TargetBoidData.NumNeighbours > 0)
			{
				CohesionForce /= TargetBoidData.NumNeighbours;
				CohesionForce -= TargetLocation;

				AlignmentForce /= TargetBoidData.NumNeighbours;
				AlignmentForce -= TargetBoidData.Velocity;
			}

			if (SeperationNeighbourCount > 0)
			{
				SeperationForce /= SeperationNeighbourCount;
				SeperationForce.Normalize();
			}

			// Clamp
			//CohesionForce = UKismetMathLibrary::ClampVectorSize(CohesionForce, 0, MaxForce);
			//AlignmentForce = UKismetMathLibrary::ClampVectorSize(AlignmentForce, 0, MaxForce);
			//SeperationForce = UKismetMathLibrary::ClampVectorSize(SeperationForce, 0, MaxForce);
			//SeekForce = UKismetMathLibrary::ClampVectorSize(SeekForce, 0, MaxForce);
			////CollisionAvoidanceForce = UKismetMathLibrary::ClampVectorSize(CollisionAvoidanceForce, 0, MaxForce);

			// Avoidance forces take precedent over all others
			if (SeperationForce.Size() == 0 && CollisionAvoidanceForce.Size() == 0)
			{
				CohesionForce *= CohesionStrength;
				AlignmentForce *= AlignmentStrength;
				SeperationForce *= SeperationStrength;
				SeekForce *= SeekStrength;
				CollisionAvoidanceForce *= CollisionAvoidanceStrength;
			}
			else
			{
				CohesionForce *= 0;
				AlignmentForce *= 0;
				SeperationForce *= SeperationStrength;
				SeekForce *= 0;
				CollisionAvoidanceForce *= CollisionAvoidanceStrength;			
			}

			const auto Force = (AlignmentForce + CohesionForce + SeperationForce + SeekForce + CollisionAvoidanceForce).GetClampedToMaxSize(MaxForce);

			// Add forces to acceleration
			TargetBoidData.Acceleration = Force;

			TargetBoidData.Velocity += TargetBoidData.Acceleration;
		}

		TargetBoidData.Velocity = UKismetMathLibrary::ClampVectorSize(TargetBoidData.Velocity, 0, TargetBoidData.MaxVelocity);
		
		const auto CurrentLocation = TargetBoidData.Transform.GetLocation();
		auto UpdatedLocation = CurrentLocation + TargetBoidData.Velocity * DeltaTime;

		// Update Transform
		float ScaleFloat = (TargetBoidData.NumNeighbours + 1) / (float)NeighboursForFullScale;
		ScaleFloat = FMath::Clamp(ScaleFloat, 0.0f, 1.0f);

		TargetBoidData.TargetScale = BoidScale + BoidScale * ScaleFloat * MaxNeighboursScaleMultiplier;
		const auto CurrentScale = TargetBoidData.Transform.GetScale3D();

		TargetBoidData.Transform.SetScale3D((TargetBoidData.TargetScale - CurrentScale) / ScaleEasing);
		TargetBoidData.Transform.SetLocation(UpdatedLocation);
		TargetBoidData.Transform.SetRotation(UKismetMathLibrary::MakeRotFromZ(TargetBoidData.Velocity).Quaternion());		
	});

	for (int i = 0; i < BoidDatas.Num(); i++)
	{
		auto& TargetBoidData = BoidDatas[i];

		// Update instanced mesh
		HierarchicalInstancedStaticMeshComponent->UpdateInstanceTransform(
			TargetBoidData.InstancedMeshIndex,
			TargetBoidData.Transform,
			true, false, true);
	}

	HierarchicalInstancedStaticMeshComponent->MarkRenderStateDirty();

	// Controller Updates
	this->CustomTimeDilation = TimeDilation;
}

FVector ABoidController::FindUnobstructedDirection(const FBoidData& TargetBoidData) const
{
	const auto* World = GetWorld();
	const auto Start = TargetBoidData.Transform.GetLocation();

	FVector BestDir = FVector::ZeroVector;
	float FurthestDistance = 0;

	int NumRaycasts = FMath::Min(MaxRaycasts, RaycastVectors.Num());

	for (int i = 0; i < NumRaycasts; i++)
	{
		FHitResult OutHit;
		FCollisionQueryParams CollisionParams;

		const auto RaycastDirection = TargetBoidData.Transform.TransformVectorNoScale(RaycastVectors[i]) * RaycastRadius;
		
		const auto End = Start + RaycastDirection;		

		if (World->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
		{
			if (OutHit.Distance > FurthestDistance)
			{
				FurthestDistance = OutHit.Distance;
				BestDir = RaycastDirection;
			}

			if (TargetBoidData.InstancedMeshIndex == DebugIndex && bShowDebug)
				DrawDebugLine(World, Start, OutHit.ImpactPoint, FColor::Red, false, 1.0f, 1, 20);

			// Inside objects
			if (TargetBoidData.InstancedMeshIndex == DebugIndex && bShowDebug && OutHit.Distance < 50)
				DrawDebugPoint(World, OutHit.ImpactPoint, 50, FColor::Red, false, 2);
		}
		else
		{
			if (TargetBoidData.InstancedMeshIndex == DebugIndex && bShowDebug)
				DrawDebugLine(World, Start, End, FColor::Blue, false, 1.0f, 1, 20);

			if (bNoCollisionGoesForward || i > 0)
				return RaycastDirection.GetSafeNormal();
			else
				return FVector::ZeroVector;
		}
	}

	if (TargetBoidData.InstancedMeshIndex == DebugIndex && bShowDebug)
		DrawDebugLine(World, Start, Start + BestDir, FColor::Green, false, 1.0f, 1, 20);
	return BestDir.GetSafeNormal();
	
}

//UE_LOG(LogTemp, Error, TEXT("Added Boid"));
//UE_LOG(LogTemp, Error, TEXT("%f"), DeltaTime);

