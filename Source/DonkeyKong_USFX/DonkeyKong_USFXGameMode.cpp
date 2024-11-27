// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_USFXGameMode.h"
#include "DonkeyKong_USFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EnemigoDragon.h"

ADonkeyKong_USFXGameMode::ADonkeyKong_USFXGameMode()
{
	// set default pawn class to our Blueprinted character
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADonkeyKong_USFXGameMode::BeginPlay()
{
	//state
	dragon = GetWorld()->SpawnActor<AEnemigoDragon>(AEnemigoDragon::StaticClass(), FVector(1208, 1610, 700), FRotator::ZeroRotator);
	dragon->InicializarEnemigo(100);
	dragon->Ataque();
}

void ADonkeyKong_USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	segundos += DeltaTime;
	if (segundos >= 2) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("puntos actuales del dragon: %d"), dragon->GetEnergia()));
	}
}