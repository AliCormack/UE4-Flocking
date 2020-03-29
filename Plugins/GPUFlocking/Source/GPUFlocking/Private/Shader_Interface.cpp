
#include "Shader_Interface.h"
#include "RenderTargetPool.h"

#include "Containers/DynamicRHIResourceArray.h" // Core module

DEFINE_LOG_CATEGORY(GPUFlockingShaderInterface);

// This will tell the engine to create the shader and where the shader entry point is.
//                            ShaderType                            ShaderPath                     Shader function name    Type
IMPLEMENT_GLOBAL_SHADER(FGlobalComputeShader_Interface, "/Shaders/Private/Flocking.usf", "MainComputeShader", SF_Compute);

void FGlobalComputeShader_Interface::SetParameters(
	FRHICommandListImmediate& RHICmdList,
	float simulationTime)
{
	check(IsInRenderingThread());
}

void FGlobalComputeShader_Interface::Compute(
	FRHICommandListImmediate& RHICmdList,	
	float simulationTime,
	UTextureRenderTarget2D* RenderTarget)
{
	check(IsInRenderingThread());
	
	FRDGBuilder GraphBuilder(RHICmdList);


	//We need to re-create FParams every itteration
	FParameters* PassParameters;
	//zero out our params
	PassParameters = GraphBuilder.AllocParameters<FGlobalComputeShader_Interface::FParameters>();

	PassParameters->simulationTime = simulationTime;
	   	  
	if (!RenderTarget)
	{
		return;
	}

	FRDGTextureDesc OutputDesc;
	OutputDesc.Extent.X = 512;
	OutputDesc.Extent.Y = 512;
	OutputDesc.Depth = 0;
	OutputDesc.Format = PF_FloatRGBA;
	OutputDesc.NumMips = 1;
	//OutputDesc.Flags = TexCreate_ShaderResource;
	OutputDesc.Flags = TexCreate_None;
	OutputDesc.TargetableFlags = TexCreate_ShaderResource | TexCreate_UAV;
	OutputDesc.bForceSeparateTargetAndShaderResource = false;


	FRDGTextureRef HairLUTTexture = GraphBuilder.CreateTexture(OutputDesc, TEXT("HairLUT"));
	PassParameters->OutputTexture = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(HairLUTTexture, 0));

	//Adding a pass
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("Flocking compute"),
		this,
		PassParameters,
		//This is different than the grouping in shader
		//This will create "Groups of threads"
		//The on in the shader, is the number of thread per group
		FIntVector(16, 16, 1));

	GraphBuilder.QueueTextureExtraction(HairLUTTexture, &ComputeShaderOutput, true);

	GraphBuilder.Execute();
	//Lock buffer to enable CPU read
	/*char* shaderData = (char*)RHICmdList.LockStructuredBuffer(StepTotal_buffer_, 0, sizeof(float), EResourceLockMode::RLM_ReadOnly);

	const float* shader_data = (const float*)RHICmdList.LockStructuredBuffer(StepTotal_buffer_, 0, sizeof(float) * 1, EResourceLockMode::RLM_ReadOnly);
	FMemory::Memcpy(StepTotalDebug.GetData(), shader_data, sizeof(float) * 1);*/

	// Resolve render target
	/*RHICmdList.CopyToResolveTarget(ComputeShaderOutput.GetReference()->GetRenderTargetItem().TargetableTexture, RenderTarget->GetRenderTargetResource()->TextureRHI, FResolveParams());



	RHICmdList.UnlockStructuredBuffer(StepTotal_buffer_);*/

	//UE_LOG(GPUFlockingShaderInterface, Display, TEXT("\n //////////////////////////// Step Total Debug  '%f'"), StepTotalDebug[0]);
}