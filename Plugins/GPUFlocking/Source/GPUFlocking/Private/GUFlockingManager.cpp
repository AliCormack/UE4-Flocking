
#include "GPUFlockingManager.h"

#include "GenerateMips.h"
#include "RenderGraph.h"
#include "RenderGraphUtils.h"
#include "RenderTargetPool.h"
#include "Kismet/KismetMathLibrary.h"

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

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef< FGlobalComputeShader_Interface > ComputeShader(GlobalShaderMap);

	for(int i = 0; i < ComputeShader->States.Num(); i++)
	{
		const auto State = ComputeShader->States[i];

		//UE_LOG(LogTemp, Error, TEXT("%f %f %f"), State.position[0], State.position[1], State.position[2]);

		AgentStates = ComputeShader->States;

		// TODO BatchUpdateInstances

		FTransform AgentTransform;
		FVector Position = FVector(State.position[0], State.position[1], State.position[2]);
		AgentTransform.SetLocation(Position);

		FVector Velocity = FVector(State.velocity[0], State.velocity[1], State.velocity[2]);
		AgentTransform.SetRotation(UKismetMathLibrary::MakeRotFromZ(Velocity).Quaternion());

		HierarchicalInstancedStaticMeshComponent->UpdateInstanceTransform(i, AgentTransform, false, true);
	}
}

void AGPUFlockingManager::Setup()
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
		
		HierarchicalInstancedStaticMeshComponent->AddInstance(FTransform());
	}

	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FGlobalComputeShader_Interface> ComputeShader(GlobalShaderMap);
	
	ENQUEUE_RENDER_COMMAND(FlockCompute)(
		[ComputeShader](FRHICommandListImmediate& RHICmdList)
	{
		ComputeShader->SetParameters(RHICmdList);
	});
}

void AGPUFlockingManager::Calculate(float DeltaTime)
{	
	FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

	TShaderMap<FGlobalShaderType>* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FGlobalComputeShader_Interface> ComputeShader(GlobalShaderMap); 

	auto CurrentStates = AgentStates;

	ENQUEUE_RENDER_COMMAND(FlockCompute)(
		[ComputeShader, DeltaTime, CurrentStates](FRHICommandListImmediate& RHICmdList)
	{
		ComputeShader->Compute(RHICmdList, DeltaTime, CurrentStates);
	});
}


