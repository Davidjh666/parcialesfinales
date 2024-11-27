// Fill out your copyright notice in the Description page of Project Settings.


#include "StateContainer.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

// Sets default values
AStateContainer::AStateContainer()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentStateIndex = 0;
}

// Called when the game starts or when spawned
void AStateContainer::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AStateContainer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AStateContainer::AddState(IIState* NewState)
{
    States.Add(NewState);
    if (NewState) 
    {
        FString StateName = NewState->GetEstado(); GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Añadiendo estado al contenedor: %s"), *StateName));
    }
    else {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Error: Intentando añadir un estado nulo al contenedor"));
    }
}

void AStateContainer::ExecuteStates()
{
    if (States.Num() > 0)
    {
        ExecuteNextState();
    }
}

void AStateContainer::ExecuteNextState() 
{
    if (CurrentStateIndex < States.Num()) 
    {
        IIState* State = States[CurrentStateIndex]; 
        FString StateName = State->GetEstado(); // Obtener el nombre o descripción del estado
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Ejecutando estado %d: %s"), CurrentStateIndex + 1, *StateName)); 
        
        State->atacar(); // Ejemplo de acción, puede variar según tu implementación 
        CurrentStateIndex++; 
        GetWorld()->GetTimerManager().SetTimer(StateTimerHandle, this, &AStateContainer::ExecuteNextState, 5.0f, false);
    }
    else 
    { 
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Todos los estados han sido ejecutados."));
    } 
}

