// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DONKEYKONG_USFX_API IIState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetEnemigo(class AEnemigoDragon* _enemigo) = 0;
	virtual FString GetEstado() = 0;
	virtual void atacar() = 0;
	virtual void moverse() = 0;
	virtual void RecuperarEnergia() = 0;
	virtual void PerderEnergia() = 0;
};