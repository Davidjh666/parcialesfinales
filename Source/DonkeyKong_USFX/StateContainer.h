// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IState.h"
#include "StateContainer.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AStateContainer : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AStateContainer();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void AddState(IIState* NewState);
    void ExecuteStates();

private:
    TArray<IIState*> States;
    int32 CurrentStateIndex;
    FTimerHandle StateTimerHandle;

    void ExecuteNextState();
};
