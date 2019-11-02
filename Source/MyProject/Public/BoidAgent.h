// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BoidAgent.generated.h"

UCLASS()
class MYPROJECT_API ABoidAgent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidAgent(const FObjectInitializer& ObjectInitializer);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
	UStaticMeshComponent* StaticMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION(BlueprintCallable)
	TSet<AActor*> GetAgentsToConsider();

	FVector Acceleration;

	FVector CalculateSeperation(TSet<AActor*>& OtherAgents);
	FVector CalculateAlignment(TSet<AActor*>& OtherAgents);
	FVector CalculateCohesion(TSet<AActor*>& OtherAgents);

};
