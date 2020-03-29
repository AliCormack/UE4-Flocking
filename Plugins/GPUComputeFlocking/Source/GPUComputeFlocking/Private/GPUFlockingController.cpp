
#include "GPUFlockingController.h"
#include "GPUComputeFlocking.h"

AGPUFlockingController::AGPUFlockingController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	TotalTime = 0;
}

void AGPUFlockingController::BeginPlay()
{
	Super::BeginPlay();

	FGPUComputeFlockingModule::Get().BeginRendering();	
}

void AGPUFlockingController::BeginDestroy()
{
	FGPUComputeFlockingModule::Get().EndRendering();
	Super::BeginDestroy();
}

void AGPUFlockingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TotalTime += DeltaTime;

	FShaderUsageExampleParameters DrawParameters
	{
		TotalTime
	};

	// If doing this for realsies, you should avoid doing this every frame unless you have to of course.
	// We set it every frame here since we're updating the end color and simulation state. Boop.
	FGPUComputeFlockingModule::Get().UpdateParameters(DrawParameters);
}