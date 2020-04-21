#pragma once
#include "GPUFlockingManager.h"

#include "GenerateMips.h"
#include "RenderGraph.h"
#include "RenderGraphUtils.h"
#include "RenderTargetPool.h"

DEFINE_LOG_CATEGORY(GPUFlocking);

AGPUFlockingManager::AGPUFlockingManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	HierarchicalInstancedStaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(this, TEXT("HierarchicalInstancedStaticMeshComponent"));
	RootComponent = HierarchicalInstancedStaticMeshComponent;

	PrimaryActorTick.bCanEverTick = true;
}

void AGPUFlockingManager::BeginPlay()
{
	Super::BeginPlay();

	Setup();
}

void AGPUFlockingManager::BeginDestroy()
{
	Super::BeginDestroy();
}

void AGPUFlockingManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Calculate(DeltaTime);
}

bool AGPUFlockingManager::Setup()
{
	for (int i = 0; i < FlockCount; i++)
	{
		const float m_spawningRange = 1000;
		FVector randomPos(
			FMath::RandRange(-m_spawningRange, m_spawningRange),
			FMath::RandRange(-m_spawningRange, m_spawningRange),
			FMath::RandRange(-m_spawningRange, m_spawningRange));

		FRotator randRotator(0, FMath::RandRange(0, 360), 0);
		auto Velocity = randRotator.Vector();

		FAgentState state;

		state.position[0] = randomPos.X;
		state.position[1] = randomPos.Y;
		state.position[2] = randomPos.Z;

		state.velocity[0] = Velocity.X;
		state.velocity[1] = Velocity.Y;
		state.velocity[2] = Velocity.Z;

		state.instanceId = i;
		AgentStates.Add(state);
	}

	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef< FGlobalComputeShader_Interface > ComputeShader(GlobalShaderMap);

	ENQUEUE_RENDER_COMMAND(FlockCompute)(
		[ComputeShader](FRHICommandListImmediate& RHICmdList)
	{
		ComputeShader->SetParameters(RHICmdList);
	});


	return true;
}

bool AGPUFlockingManager::Calculate(float DeltaTime)
{	
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef< FGlobalComputeShader_Interface > ComputeShader(GlobalShaderMap);

	auto CurrentStates = AgentStates;
	TArray<FAgentState> ResultStates;

	for (int i = 0; i < FlockCount; i++)
	{
		ResultStates.Add(FAgentState());
	}

	ENQUEUE_RENDER_COMMAND(FlockCompute)(
		[ComputeShader, DeltaTime, CurrentStates, &ResultStates](FRHICommandListImmediate& RHICmdList)
	{
		ComputeShader->Compute(RHICmdList, DeltaTime, CurrentStates, ResultStates);
	});

	return true;
}


