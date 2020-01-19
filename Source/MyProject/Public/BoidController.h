// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "BoidController.generated.h"

USTRUCT(BlueprintType)
struct FBoidData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FTransform Transform;	

	UPROPERTY(BlueprintReadOnly)
	FVector Velocity;

	UPROPERTY(BlueprintReadOnly)
	FVector Acceleration;

	UPROPERTY(BlueprintReadOnly)
	float MaxVelocity;

	UPROPERTY(BlueprintReadOnly)
	int InstancedMeshIndex;
};

UCLASS()
class MYPROJECT_API ABoidController : public AActor
{
	GENERATED_BODY()

public:

	ABoidController(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Setup")
		int NumBoids = 300;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Setup")
		float SpawnRadius = 3000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Setup")
	float MininmumMaxVelocity = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Setup")
	float MaximumMaxVelocity = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Setup")
		FVector BoidScale = FVector::OneVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Setup")
		float MaxForce = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids")
		float SeperationRadius = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids")
		float SeekStopRadius = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Force Strengths")
		float CohesionStrength = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Force Strengths")
		float AlignmentStrength = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Force Strengths")
		float SeperationStrength = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Force Strengths")
		float SeekStrength = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Force Strengths")
		float CollisionAvoidanceStrength = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Neighbour Detection")
		float VisionConeAngle = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Neighbour Detection")
		float NeighbourRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Neighbour Detection")
		int MaxNeighbours = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Controller", meta = (ClampMin = "0", UIMin = "0"))
		float TimeDilation = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Collision")
	int NumRaycastVectors = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Collision")
	int MaxRaycasts = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Collision")
	int RaycastRadius = 700;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boids|Collision")
	bool bNoCollisionGoesForward = true;

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UInstancedStaticMeshComponent* HierarchicalInstancedStaticMeshComponent;

	UPROPERTY(BlueprintReadWrite)
		FTransform SeekTransform;

	UPROPERTY(BlueprintReadOnly)
		TArray<FBoidData> BoidDatas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int DebugIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShowDebug;

private:

	FVector GetRandomSpawnLocation() const;

	FVector BoidsOrigin;

	void CreateBoid();

	FVector FindUnobstructedDirection(const FBoidData& TargetBoidData) const;

	static TArray<FVector> RaycastVectors;
	void CalculateRaycastVectors();

};
