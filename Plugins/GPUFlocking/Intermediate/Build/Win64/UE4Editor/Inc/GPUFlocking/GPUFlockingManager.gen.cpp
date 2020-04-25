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
	ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
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
			float DeltaTime;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GPUFlockingManager_eventCalculate_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGPUFlockingManager_Calculate_Statics::NewProp_DeltaTime,
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGPUFlockingManager, nullptr, "Setup", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGPUFlockingManager_Setup_Statics::Function_MetaDataParams)) };
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HierarchicalInstancedStaticMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HierarchicalInstancedStaticMeshComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGPUFlockingManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GPUFlocking,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGPUFlockingManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGPUFlockingManager_Calculate, "Calculate" }, // 173055406
		{ &Z_Construct_UFunction_AGPUFlockingManager_Setup, "Setup" }, // 905506561
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_HierarchicalInstancedStaticMeshComponent_MetaData[] = {
		{ "Category", "GPUFlockingManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GPUFlockingManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_HierarchicalInstancedStaticMeshComponent = { "HierarchicalInstancedStaticMeshComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGPUFlockingManager, HierarchicalInstancedStaticMeshComponent), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_HierarchicalInstancedStaticMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_HierarchicalInstancedStaticMeshComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGPUFlockingManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGPUFlockingManager_Statics::NewProp_HierarchicalInstancedStaticMeshComponent,
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
	IMPLEMENT_CLASS(AGPUFlockingManager, 484219514);
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
