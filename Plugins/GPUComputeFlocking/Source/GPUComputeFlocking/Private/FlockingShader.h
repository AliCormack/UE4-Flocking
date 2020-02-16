
#pragma once

#include "CoreMinimal.h"
#include "GPUComputeFlocking.h"

class FFlockingShader
{
public:
	static void RunComputeShader_RenderThread(FRHICommandListImmediate& RHICmdList, const FShaderUsageExampleParameters& DrawParameters, FUnorderedAccessViewRHIRef ComputeShaderOutputUAV);
};
