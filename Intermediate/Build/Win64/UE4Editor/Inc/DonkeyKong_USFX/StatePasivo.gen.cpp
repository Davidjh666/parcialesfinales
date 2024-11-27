// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonkeyKong_USFX/StatePasivo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStatePasivo() {}
// Cross Module References
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_AStatePasivo_NoRegister();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_AStatePasivo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_DonkeyKong_USFX();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_UIState_NoRegister();
// End Cross Module References
	void AStatePasivo::StaticRegisterNativesAStatePasivo()
	{
	}
	UClass* Z_Construct_UClass_AStatePasivo_NoRegister()
	{
		return AStatePasivo::StaticClass();
	}
	struct Z_Construct_UClass_AStatePasivo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStatePasivo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_DonkeyKong_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStatePasivo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StatePasivo.h" },
		{ "ModuleRelativePath", "StatePasivo.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AStatePasivo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIState_NoRegister, (int32)VTABLE_OFFSET(AStatePasivo, IIState), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStatePasivo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStatePasivo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStatePasivo_Statics::ClassParams = {
		&AStatePasivo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AStatePasivo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStatePasivo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStatePasivo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStatePasivo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStatePasivo, 3061427218);
	template<> DONKEYKONG_USFX_API UClass* StaticClass<AStatePasivo>()
	{
		return AStatePasivo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStatePasivo(Z_Construct_UClass_AStatePasivo, &AStatePasivo::StaticClass, TEXT("/Script/DonkeyKong_USFX"), TEXT("AStatePasivo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStatePasivo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
