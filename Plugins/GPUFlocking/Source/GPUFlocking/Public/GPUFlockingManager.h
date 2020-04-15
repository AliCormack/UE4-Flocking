#pragma once

#include "CoreMinimal.h"
#include "RenderGraph.h" //The only thing you need for RDG
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

public:

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool Setup();

	UFUNCTION(BlueprintCallable)
	bool Calculate(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextureRenderTarget2D* RenderTarget_Output;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float simulationTime = 0; 

};
