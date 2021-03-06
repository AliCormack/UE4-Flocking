
#include "Shader_Interface.h"
#include "RenderTargetPool.h"


DEFINE_LOG_CATEGORY(GPUFlockingShaderInterface);



// This will tell the engine to create the shader and where the shader entry point is.
//                            ShaderType                            ShaderPath                     Shader function name    Type
IMPLEMENT_GLOBAL_SHADER(FGlobalComputeShader_Interface, "/Shaders/Private/Flocking.usf", "MainComputeShader", SF_Compute);

void FGlobalComputeShader_Interface::SetParameters(FRHICommandListImmediate& RHICmdList)
{
	check(IsInRenderingThread());

	//StepTotal_RA_.SetNum(1);
	//FMemory::Memcpy(StepTotal_RA_.GetData(), StepTotalDebug.GetData(), sizeof(float) * 1);
	//StepTotal_resource_.ResourceArray = &StepTotal_RA_;
	//StepTotal_buffer_ = RHICreateStructuredBuffer(sizeof(float), sizeof(float) * 1, BUF_ShaderResource | BUF_UnorderedAccess, StepTotal_resource_);
	//StepTotal_UAV_ = RHICreateUnorderedAccessView(StepTotal_buffer_, /* bool bUseUAVCounter */ false, /* bool bAppendBuffer */ false);

	
}

void FGlobalComputeShader_Interface::Compute(
	FRHICommandListImmediate& RHICmdList,	
	float DeltaTime,
	const TArray<FAgentState>& CurrentStates)
{
	check(IsInRenderingThread());

	FRDGBuilder GraphBuilder(RHICmdList);

	//We need to re-create FParams every itteration
	FParameters* PassParameters;
	//zero out our params
	PassParameters = GraphBuilder.AllocParameters<FGlobalComputeShader_Interface::FParameters>();

	PassParameters->DeltaTime = DeltaTime;

	// First half of array is for new state data to be written to, latter half is for reading data.
	TResourceArray<FAgentState> data;
	for (int i = 0; i < FlockCount; i++) {
		data.Add(CurrentStates[i]);
	}
	for (int i = 0; i < FlockCount; i++) {
		data.Add(CurrentStates[i]);
	}

	FRHIResourceCreateInfo resource;
	resource.ResourceArray = &data;
	FStructuredBufferRHIRef buffer = RHICreateStructuredBuffer(sizeof(FAgentState), sizeof(FAgentState) * FlockCount * 2, BUF_ShaderResource | BUF_UnorderedAccess, resource);
	FUnorderedAccessViewRHIRef uav = RHICreateUnorderedAccessView(buffer, false, false);
	PassParameters->Data = uav;

	FRDGTextureDesc OutputDesc;
	OutputDesc.Extent.X = 512;
	OutputDesc.Extent.Y = 512;
	OutputDesc.Depth = 0;
	OutputDesc.Format = PF_FloatRGBA;
	OutputDesc.NumMips = 1;
	//OutputDesc.Flags = TexCreate_ShaderResource;
	//OutputDesc.Flags = TexCreate_None;
	OutputDesc.TargetableFlags = TexCreate_ShaderResource | TexCreate_UAV;
	//OutputDesc.bForceSeparateTargetAndShaderResource = false;

	//Adding a pass
	FComputeShaderUtils::AddPass(
		GraphBuilder,
		RDG_EVENT_NAME("Flocking compute"),
		this,
		PassParameters,
		//This is different than the grouping in shader
		//This will create "Groups of threads"
		//The on in the shader, is the number of thread per group
		FIntVector(1, 256, 1));

	//GraphBuilder.QueueTextureExtraction(HairLUTTexture, &ComputeShaderOutput, true);

	GraphBuilder.Execute();
	//Lock buffer to enable CPU read
	//char* shaderData = (char*)RHICmdList.LockStructuredBuffer(StepTotal_buffer_, 0, sizeof(float), EResourceLockMode::RLM_ReadOnly);

	char* shader_data = (char*)RHICmdList.LockStructuredBuffer(buffer, 0, sizeof(FAgentState) * FlockCount * 2, EResourceLockMode::RLM_ReadOnly);
	
	TArray<FAgentState> result;
	result.Reserve(FlockCount);

	FAgentState* p = (FAgentState*)shader_data;
	for (int32 Row = 0; Row < FlockCount; ++Row) {
		result.Add(*p);
		p++;
	}

	States = result;

	//FMemory::Memcpy(States.GetData(), shader_data, sizeof(FAgentState) * 1);

	// Resolve render target
	//RHICmdList.CopyToResolveTarget(ComputeShaderOutput.GetReference()->GetRenderTargetItem().TargetableTexture, RenderTarget->GetRenderTargetResource()->TextureRHI, FResolveParams());



	RHICmdList.UnlockStructuredBuffer(buffer);

	//UE_LOG(GPUFlockingShaderInterface, Display, TEXT("\n //////////////////////////// Step Total Debug  '%f'"), StepTotalDebug[0]);
}