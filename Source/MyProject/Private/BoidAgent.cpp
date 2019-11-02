#include "BoidAgent.h"

ABoidAgent::ABoidAgent(const FObjectInitializer& ObjectInitializer)	: Super(ObjectInitializer)
{
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	PrimaryActorTick.bCanEverTick = true;

}

void ABoidAgent::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABoidAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//auto AgentsToConsider = GetAgentsToConsider();

	//auto Seperation = CalculateSeperation(AgentsToConsider);
	//auto Alignment = CalculateAlignment(AgentsToConsider);
	//auto Cohesion = FVector(0.01f, 0, 0);// CalculateCohesion(AgentsToConsider);

	//Acceleration += Seperation + Alignment + Cohesion;

	//FVector NewVelocity = StaticMeshComponent->ComponentVelocity + Acceleration;
	//NewVelocity = NewVelocity.GetClampedToMaxSize(MaxSpeed);

	//StaticMeshComponent->SetPhysicsLinearVelocity(NewVelocity);

	//StaticMeshComponent->AddForce(Cohesion);

	/*for (auto Agent : AgentsToConsider)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *Agent->GetName())
	}*/

}

TSet<AActor*> ABoidAgent::GetAgentsToConsider()
{
	TSet<AActor*> OverlappingActors;
	
	return OverlappingActors;
}

FVector ABoidAgent::CalculateSeperation(TSet<AActor*>& OtherAgents)
{
	const auto DesiredSeperation = 100.0f;
	auto Steer = FVector::ZeroVector;
	/*auto Count = 0;

	for (auto* Agent : OtherAgents)
	{
		auto Distance = FVector::Distance(GetActorLocation(), Agent->GetActorLocation());

		if (Distance > 0 && Distance < DesiredSeperation)
		{
			auto Difference = GetActorLocation() - Agent->GetActorLocation();
			Difference.Normalize();
			Difference /= Distance;
			Steer += Difference;
			Count++;
		}
	}

	if (Count > 0)
	{
		Steer /= Count;
	}

	if (Steer.Size() > 0)
	{
		Steer.Normalize();
		Steer *= MaxSpeed;
		Steer -= StaticMeshComponent->ComponentVelocity;
		Steer.GetClampedToMaxSize(MaxSpeed);
	}*/

	return Steer;
}

FVector ABoidAgent::CalculateAlignment(TSet<AActor*>& OtherAgents)
{
	return FVector::ZeroVector;
}

FVector ABoidAgent::CalculateCohesion(TSet<AActor*>& OtherAgents)
{
	return FVector::ZeroVector;
}