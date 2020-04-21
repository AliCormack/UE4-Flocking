#pragma once

#include "CoreMinimal.h"
#include "RenderGraph.h" //The only thing you need for RDG
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Shader_Interface.h"
#include "GPUFlockingManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GPUFlocking, Verbose, All);

UCLASS(Blueprintable, BlueprintType)
class AGPUFlockingManager : public AActor
{
	GENERATED_BODY()

public:

	AGPUFlockingManager(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool Setup();

	UFUNCTION(BlueprintCallable)
	bool Calculate(float DeltaTime);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInstancedStaticMeshComponent* HierarchicalInstancedStaticMeshComponent;

	int FlockCount = 10;

	TArray<FAgentState> AgentStates;
};
