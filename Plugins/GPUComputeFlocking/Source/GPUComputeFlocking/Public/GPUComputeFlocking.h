// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

#include "RenderGraphResources.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"

// This struct contains all the data we need to pass from the game thread to draw our effect.
struct FShaderUsageExampleParameters
{
	UTextureRenderTarget2D* RenderTarget;
	float Time;

	FIntPoint GetRenderTargetSize() const
	{
		return CachedRenderTargetSize;
	}

	FShaderUsageExampleParameters() { }
	FShaderUsageExampleParameters(UTextureRenderTarget2D* InRenderTarget)
		: RenderTarget(InRenderTarget)
		, Time(0)
	{
	}

private:
	FIntPoint CachedRenderTargetSize;
};

class FGPUComputeFlockingModule : public IModuleInterface
{
public:
	static inline FGPUComputeFlockingModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FGPUComputeFlockingModule>("GPUComputeFlocking");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("GPUComputeFlocking");
	}

public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	// Call this when you want to hook onto the renderer and start drawing. The shader will be executed once per frame.
	void BeginRendering();

	// When you are done, call this to stop drawing.
	void EndRendering();

	// Call this whenever you have new parameters to share. You could set this up to update different sets of properties at
	// different intervals to save on locking and GPU transfer time.
	void UpdateParameters(FShaderUsageExampleParameters& DrawParameters);

private:
	TRefCountPtr<IPooledRenderTarget> ComputeShaderOutput;
	FShaderUsageExampleParameters CachedShaderUsageExampleParameters;
	FDelegateHandle OnPostResolvedSceneColorHandle;
	FCriticalSection RenderEveryFrameLock;
	volatile bool bCachedParametersValid;

	void PostResolveSceneColor_RenderThread(FRHICommandListImmediate& RHICmdList, class FSceneRenderTargets& SceneContext);
	void Draw_RenderThread(const FShaderUsageExampleParameters& DrawParameters);

};
