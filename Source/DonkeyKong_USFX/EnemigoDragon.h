// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IState.h" //state
#include "EnemigoDragon.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AEnemigoDragon : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigoDragon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Componente de Malla Esquel�tica
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMesh;

	// Asset de animaci�n
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* MyAnimationAsset; // o UAnimMontage* MyAnimationAsset;

	//Patron State
private:
	IIState* EstadoPasivo;
	IIState* EstadoAgresivo;
	IIState* Estado;
	int energia = 0;

public:
	void InicializarEnemigo(int _energia);
	void EstablecerEstado(IIState* _estado);	
	void Ataque();
	void Moverse();
	FORCEINLINE int GetEnergia() { return energia; }
	FORCEINLINE FString GetEstadoActual() { return "El estado actual del Dragon es " + Estado->GetEstado(); }
	FORCEINLINE IIState* GetEstadoPasivo() { return EstadoPasivo; }
	FORCEINLINE IIState* GetEstadoAgresivo() { return EstadoAgresivo; }
	FORCEINLINE void RecuperarEnergia() { energia += 7; };
	FORCEINLINE void PerderEnergia() { energia -= 2; };
};
