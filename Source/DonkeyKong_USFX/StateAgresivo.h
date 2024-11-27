// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IState.h"
#include "StateAgresivo.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AStateAgresivo : public AActor, public IIState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStateAgresivo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class AEnemigoDragon* enemigo;
	FVector PosicionInicial;
	FVector LimiteInicial;
	FVector LimiteFinal;
	FVector posicionActual;
	FRotator mirar;
	float tiempo;
	float incremento;
	bool vigilar;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetEnemigo(class AEnemigoDragon* _enemigo) override;
	FString GetEstado() override;
	void atacar() override;
	void moverse() override;
	void RecuperarEnergia() override {};
	void PerderEnergia() override;
	FTimerHandle ataque;
	APawn* Jugador;
};
