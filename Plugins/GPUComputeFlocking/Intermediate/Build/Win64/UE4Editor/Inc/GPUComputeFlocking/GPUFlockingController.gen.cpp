// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GPUComputeFlocking/Public/GPUFlockingController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGPUFlockingController() {}
// Cross Module References
	GPUCOMPUTEFLOCKING_API UClass* Z_Construct_UClass_AGPUFlockingController_NoRegister();
	GPUCOMPUTEFLOCKING_API UClass* Z_Construct_UClass_AGPUFlockingController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GPUComputeFlocking();
// End Cross Module References
	void AGPUFlockingController::StaticRegisterNativesAGPUFlockingController()
	{
	}
	UClass* Z_Construct_UClass_AGPUFlockingController_NoRegister()
	{
		return AGPUFlockingController::StaticClass();
	}
	struct Z_Construct_UClass_AGPUFlockingController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGPUFlockingController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GPUComputeFlocking,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGPUFlockingController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GPUFlockingController.h" },
		{ "ModuleRelativePath", "Public/GPUFlockingController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGPUFlockingController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGPUFlockingController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGPUFlockingController_Statics::ClassParams = {
		&AGPUFlockingController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGPUFlockingController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGPUFlockingController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGPUFlockingController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGPUFlockingController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGPUFlockingController, 3989143100);
	template<> GPUCOMPUTEFLOCKING_API UClass* StaticClass<AGPUFlockingController>()
	{
		return AGPUFlockingController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGPUFlockingController(Z_Construct_UClass_AGPUFlockingController, &AGPUFlockingController::StaticClass, TEXT("/Script/GPUComputeFlocking"), TEXT("AGPUFlockingController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGPUFlockingController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
