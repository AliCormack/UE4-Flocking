// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GPUFLOCKING_GPUFlockingManager_generated_h
#error "GPUFlockingManager.generated.h already included, missing '#pragma once' in GPUFlockingManager.h"
#endif
#define GPUFLOCKING_GPUFlockingManager_generated_h

#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_SPARSE_DATA
#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCalculate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_DeltaTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Calculate(Z_Param_DeltaTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetup) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Setup(); \
		P_NATIVE_END; \
	}


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCalculate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_DeltaTime); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Calculate(Z_Param_DeltaTime); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetup) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Setup(); \
		P_NATIVE_END; \
	}


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGPUFlockingManager(); \
	friend struct Z_Construct_UClass_AGPUFlockingManager_Statics; \
public: \
	DECLARE_CLASS(AGPUFlockingManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GPUFlocking"), NO_API) \
	DECLARE_SERIALIZER(AGPUFlockingManager)


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAGPUFlockingManager(); \
	friend struct Z_Construct_UClass_AGPUFlockingManager_Statics; \
public: \
	DECLARE_CLASS(AGPUFlockingManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GPUFlocking"), NO_API) \
	DECLARE_SERIALIZER(AGPUFlockingManager)


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGPUFlockingManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGPUFlockingManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGPUFlockingManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGPUFlockingManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGPUFlockingManager(AGPUFlockingManager&&); \
	NO_API AGPUFlockingManager(const AGPUFlockingManager&); \
public:


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGPUFlockingManager(AGPUFlockingManager&&); \
	NO_API AGPUFlockingManager(const AGPUFlockingManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGPUFlockingManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGPUFlockingManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGPUFlockingManager)


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_PRIVATE_PROPERTY_OFFSET
#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_11_PROLOG
#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_PRIVATE_PROPERTY_OFFSET \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_SPARSE_DATA \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_RPC_WRAPPERS \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_INCLASS \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_PRIVATE_PROPERTY_OFFSET \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_SPARSE_DATA \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_INCLASS_NO_PURE_DECLS \
	UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GPUFLOCKING_API UClass* StaticClass<class AGPUFlockingManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE4_Flocking_Plugins_GPUFlocking_Source_GPUFlocking_Public_GPUFlockingManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
