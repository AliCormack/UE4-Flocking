#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h" //ShaderCore module

#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"

#include "RenderGraph.h" //The only thing you need for RDG

DECLARE_LOG_CATEGORY_EXTERN(GPUFlockingShaderInterface, Verbose, All);

///*****************************************************************************/
///* This class is what encapsulates the shader in the engine.                 */
///* It is the main bridge between the HLSL (.usf file) and the engine itself. */
///*****************************************************************************/
class FGlobalComputeShader_Interface : public FGlobalShader {

	DECLARE_GLOBAL_SHADER(FGlobalComputeShader_Interface)
	
	SHADER_USE_PARAMETER_STRUCT(FGlobalComputeShader_Interface, FGlobalShader)
		BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(float, simulationTime)
		SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<FVector4>, OutputTexture)
	END_SHADER_PARAMETER_STRUCT()

	//Don't compile for a platform we don't support.
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& PermutationParams, FShaderCompilerEnvironment& OutEnvironment) {
		FGlobalShader::ModifyCompilationEnvironment(PermutationParams, OutEnvironment);
		//OutEnvironment.CompilerFlags.Add(CFLAG_StandardOptimization);
		////OutEnvironment.CompilerFlags.Add(CFLAG_OnChip);
		//OutEnvironment.CompilerFlags.Add(CFLAG_PreferFlowControl);
		//OutEnvironment.CompilerFlags.Add(CFLAG_Debug);
		//OutEnvironment.CompilerFlags.Add(CFLAG_KeepDebugInfo);
	}

	static bool ShouldCache(EShaderPlatform platform) {
		// Could skip compiling if the platform does not support DirectX Shader Model 5, for example, like the following.
		return IsFeatureLevelSupported(platform, ERHIFeatureLevel::SM5);
	}

public:
	
	//This is a reference to our data on the GPU, without it, we would need to pass the entire buffer to the GPU for our next itteration
	// DATA HERE

	TRefCountPtr<IPooledRenderTarget> ComputeShaderOutput;

	//Send our data to the gpu, and do our first itteration
	void SetParameters(
		FRHICommandListImmediate& RHICmdList,
		float simulationTime);

	//Data is already on GPU, do a single itteration
	void Compute(
		FRHICommandListImmediate& RHICmdList,
		float simulationTime,
		UTextureRenderTarget2D* RenderTarget
	);
};
