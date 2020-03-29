// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPUFlockingController.generated.h"

UCLASS()
class AGPUFlockingController : public AActor
{
	GENERATED_BODY()

public:

	AGPUFlockingController(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:

	virtual void Tick(float DeltaTime) override;

private:

	float TotalTime;

};
