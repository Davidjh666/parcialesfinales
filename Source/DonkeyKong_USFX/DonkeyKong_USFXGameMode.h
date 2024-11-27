// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StateContainer.h" // Nueva inclusión
#include "DonkeyKong_USFXGameMode.generated.h"

UCLASS(minimalapi)
class ADonkeyKong_USFXGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ADonkeyKong_USFXGameMode();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    float segundos = 0;
    class AEnemigoDragon* dragon;
    class AStateContainer* StateContainer;

private:
    void SetupStateContainer(); // Nuevo método
};




