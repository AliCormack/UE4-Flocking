#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h" //ShaderCore module

#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"

#include "RenderGraph.h" //The only thing you need for RDG

#include "Containers/DynamicRHIResourceArray.h" // Core module

// Must match flocking.usf::FState_GPU
struct FAgentState
{
	int32 instanceId = 0;
	float position[3] = { 0, 0, 0 };
	float velocity[3] = { 0, 0, 0 };
	float acceleration[3] = { 0, 0, 0 };
};

DECLARE_LOG_CATEGORY_EXTERN(GPUFlockingShaderInterface, Verbose, All);

///*****************************************************************************/
///* This class is what encapsulates the shader in the engine.                 */
///* It is the main bridge between the HLSL (.usf file) and the engine itself. */
///*****************************************************************************/
class FGlobalComputeShader_Interface : public FGlobalShader {

	DECLARE_GLOBAL_SHADER(FGlobalComputeShader_Interface)

	/*BEGIN_UNIFORM_BUFFER_STRUCT(FConstantParameters, )
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(int, fishCount)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, radiusCohesion)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, radiusSeparation)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, radiusAlignment)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, mapRangeX)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, mapRangeY)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, mapRangeZ)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, kCohesion)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, kSeparation)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, kAlignment)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, maxAcceleration)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(float, maxVelocity)
		DECLARE_UNIFORM_BUFFER_STRUCT_MEMBER(int, calculationsPerThread)
	END_UNIFORM_BUFFER_STRUCT(FConstantParameters)*/
	
	SHADER_USE_PARAMETER_STRUCT(FGlobalComputeShader_Interface, FGlobalShader)
		BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(float, DeltaTime)
		SHADER_PARAMETER_UAV(RWStructuredBuffer<FAgentState>, Data)
		//SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<FVector4>, OutputTexture)
	END_SHADER_PARAMETER_STRUCT()

	//Don't compile for a platform we don't support.
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& PermutationParams, FShaderCompilerEnvironment& OutEnvironment) {
		FGlobalShader::ModifyCompilationEnvironment(PermutationParams, OutEnvironment);
		OutEnvironment.CompilerFlags.Add(CFLAG_StandardOptimization);
		//OutEnvironment.CompilerFlags.Add(CFLAG_OnChip);
		OutEnvironment.CompilerFlags.Add(CFLAG_PreferFlowControl);
		OutEnvironment.CompilerFlags.Add(CFLAG_Debug);
		OutEnvironment.CompilerFlags.Add(CFLAG_KeepDebugInfo);
	}

	static bool ShouldCache(EShaderPlatform platform) {
		// Could skip compiling if the platform does not support DirectX Shader Model 5, for example, like the following.
		return IsFeatureLevelSupported(platform, ERHIFeatureLevel::SM5);
	}

public:
	
	//This is a reference to our data on the GPU, without it, we would need to pass the entire buffer to the GPU for our next itteration
	// DATA HERE

	/*TArray<float> StepTotalDebug = { 0 };
	TResourceArray<float> StepTotal_RA_;
	FRHIResourceCreateInfo StepTotal_resource_;
	FStructuredBufferRHIRef StepTotal_buffer_;
	FUnorderedAccessViewRHIRef StepTotal_UAV_;*/

	TArray<FAgentState> States;

	int FlockCount = 1000;

	TRefCountPtr<IPooledRenderTarget> ComputeShaderOutput;

	//Send our data to the gpu, and do our first itteration
	void SetParameters(FRHICommandListImmediate& RHICmdList);

	//Data is already on GPU, do a single itteration
	void Compute(
		FRHICommandListImmediate& RHICmdList,
		float DeltaTime,
		const TArray<FAgentState>& CurrentStates);
};

