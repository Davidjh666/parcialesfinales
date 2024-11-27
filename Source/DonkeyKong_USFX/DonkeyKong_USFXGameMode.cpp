// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_USFXGameMode.h"
#include "DonkeyKong_USFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EnemigoDragon.h"
#include "StateAgresivo.h"
#include "StatePasivo.h"

ADonkeyKong_USFXGameMode::ADonkeyKong_USFXGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void ADonkeyKong_USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    dragon = GetWorld()->SpawnActor<AEnemigoDragon>(AEnemigoDragon::StaticClass(), FVector(1208, 1610, 700), FRotator::ZeroRotator);
    dragon->InicializarEnemigo(100);

    SetupStateContainer(); // Configurar el contenedor de estados
}

void ADonkeyKong_USFXGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    segundos += DeltaTime;
    if (segundos >= 2)
    {
        /*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("puntos actuales del dragon: %d"), dragon->GetEnergia()));*/
    }
}

void ADonkeyKong_USFXGameMode::SetupStateContainer()
{
    StateContainer = GetWorld()->SpawnActor<AStateContainer>(AStateContainer::StaticClass());

    IIState* Agresivo = GetWorld()->SpawnActor<AStateAgresivo>(AStateAgresivo::StaticClass());
    IIState* Pasivo = GetWorld()->SpawnActor<AStatePasivo>(AStatePasivo::StaticClass());

    StateContainer->AddState(Agresivo);
    StateContainer->AddState(Pasivo);
    StateContainer->AddState(Agresivo);
    StateContainer->AddState(Pasivo);
    StateContainer->AddState(Agresivo);

    StateContainer->ExecuteStates(); // Iniciar la ejecución de los estados
}
