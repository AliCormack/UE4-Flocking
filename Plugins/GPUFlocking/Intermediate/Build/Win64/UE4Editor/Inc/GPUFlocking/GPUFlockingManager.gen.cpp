// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GPUFlocking/Public/GPUFlockingManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGPUFlockingManager() {}
// Cross Module References
	GPUFLOCKING_API UClass* Z_Construct_UClass_AGPUFlockingManager_NoRegister();
	GPUFLOCKING_API UClass* Z_Construct_UClass_AGPUFlockingManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GPUFlocking();
	GPUFLOCKING_API UFunction* Z_Construct_UFunction_AGPUFlockingManager_Calculate();
	GPUFLOCKING_API UFunction* Z_Construct_UFunction_AGPUFlockingManager_Setup();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
// End Cross Module References
	void AGPUFlockingManager::StaticRegisterNativesAGPUFlockingManager()
	{
		UClass* Class = AGPUFlockingManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Calculate", &AGPUFlockingManager::execCalculate },
			{ "Setup", &AGPUFlockingManager::execSetup },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics
	{
		struct GPUFlockingManager_eventCalculate_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GPUFlockingManager_eventCalculate_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GPUFlockingManager_eventCalculate_Parms), &Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGPUFlockingManager, nullptr, "Calculate", nullptr, nullptr, sizeof(GPUFlockingManager_eventCalculate_Parms), Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGPUFlockingManager_Calculate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics
	{
		struct GPUFlockingManager_eventSetup_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GPUFlockingManager_eventSetup_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(GPUFlockingManager_eventSetup_Parms), &Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGPUFlockingManager, nullptr, "Setup", nullptr, nullptr, sizeof(GPUFlockingManager_eventSetup_Parms), Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGPUFlockingManager_Setup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGPUFlockingManager_NoRegister()
	{
		return AGPUFlockingManager::StaticClass();
	}
	struct Z_Construct_UClass_AGPUFlockingManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_simulationTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_simulationTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RenderTarget_Output_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RenderTarget_Output;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGPUFlockingManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GPUFlocking,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGPUFlockingManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGPUFlockingManager_Calculate, "Calculate" }, // 2147268302
		{ &Z_Construct_UFunction_AGPUFlockingManager_Setup, "Setup" }, // 2144844264
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGPUFlockingManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "GPUFlockingManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_simulationTime_MetaData[] = {
		{ "Category", "GPUFlockingManager" },
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_simulationTime = { "simulationTime", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGPUFlockingManager, simulationTime), METADATA_PARAMS(Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_simulationTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_simulationTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_RenderTarget_Output_MetaData[] = {
		{ "Category", "GPUFlockingManager" },
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_RenderTarget_Output = { "RenderTarget_Output", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGPUFlockingManager, RenderTarget_Output), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_RenderTarget_Output_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_RenderTarget_Output_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGPUFlockingManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_simulationTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_RenderTarget_Output,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGPUFlockingManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGPUFlockingManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGPUFlockingManager_Statics::ClassParams = {
		&AGPUFlockingManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AGPUFlockingManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AGPUFlockingManager_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGPUFlockingManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGPUFlockingManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGPUFlockingManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGPUFlockingManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGPUFlockingManager, 3337705887);
	template<> GPUFLOCKING_API UClass* StaticClass<AGPUFlockingManager>()
	{
		return AGPUFlockingManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGPUFlockingManager(Z_Construct_UClass_AGPUFlockingManager, &AGPUFlockingManager::StaticClass, TEXT("/Script/GPUFlocking"), TEXT("AGPUFlockingManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGPUFlockingManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif