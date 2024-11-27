// Fill out your copyright notice in the Description page of Project Settings.


#include "StatePasivo.h"
#include "EnemigoDragon.h"

// Sets default values
AStatePasivo::AStatePasivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStatePasivo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStatePasivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStatePasivo::SetEnemigo(AEnemigoDragon* _enemigo)
{
	enemigo = _enemigo;
}

FString AStatePasivo::GetEstado()
{
	return "El Dragon esta en estado pasivo, atacalo!!!!!!!";
}

void AStatePasivo::atacar()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("El dragon esta en estado pasivo por desgaste, no puede atacar")));
	GetWorld()->GetTimerManager().SetTimer(energia, this, &AStatePasivo::RecuperarEnergia, 0.5f, true);
}

void AStatePasivo::moverse()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("El dragon esta en estado pasivo por desgaste, no puede moverse")));
	GetWorld()->GetTimerManager().SetTimer(energia, this, &AStatePasivo::RecuperarEnergia, 0.5f, true);
}

void AStatePasivo::RecuperarEnergia()
{
	if (enemigo->GetEnergia()<=100) {
		enemigo->RecuperarEnergia();
	}
	else {
		GetWorld()->GetTimerManager().ClearTimer(energia);
		enemigo->EstablecerEstado(enemigo->GetEstadoAgresivo());
	}
}
