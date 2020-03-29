#pragma once
#include "GPUFlockingManager.h"
#include "Shader_Interface.h"

#include "GenerateMips.h"
#include "RenderGraph.h"
#include "RenderGraphUtils.h"
#include "RenderTargetPool.h"

DEFINE_LOG_CATEGORY(GPUFlocking);

AGPUFlockingManager::AGPUFlockingManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGPUFlockingManager::BeginPlay()
{
	Super::BeginPlay();
}

void AGPUFlockingManager::BeginDestroy()
{
	Super::BeginDestroy();
}

void AGPUFlockingManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

bool AGPUFlockingManager::Setup()
{
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef< FGlobalComputeShader_Interface > ComputeShader(GlobalShaderMap);

	float simulationTime_out = simulationTime;

	ENQUEUE_RENDER_COMMAND(WeatherCompute)(
		[ComputeShader, simulationTime_out](FRHICommandListImmediate& RHICmdList)
	{
		ComputeShader->SetParameters(RHICmdList, simulationTime_out);
	});


	return true;
}

bool AGPUFlockingManager::Calculate()
{	
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef< FGlobalComputeShader_Interface > ComputeShader(GlobalShaderMap);

	float simulationTime_out = simulationTime;

	UTextureRenderTarget2D* RenderTarget_Output_out = RenderTarget_Output;

	ENQUEUE_RENDER_COMMAND(WeatherCompute)(
		[ComputeShader, simulationTime_out, RenderTarget_Output_out](FRHICommandListImmediate& RHICmdList)
	{
		ComputeShader->Compute(RHICmdList, simulationTime_out, RenderTarget_Output_out);
	});

	return true;
}

