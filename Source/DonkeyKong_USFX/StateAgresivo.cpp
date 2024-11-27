// Fill out your copyright notice in the Description page of Project Settings.


#include "StateAgresivo.h"
#include "Kismet/GameplayStatics.h"
#include "EnemigoDragon.h"

// Sets default values
AStateAgresivo::AStateAgresivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStateAgresivo::BeginPlay()
{
	Super::BeginPlay();
    Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    vigilar = true;
	incremento = 6.0f;
	tiempo = 0.0f;
}

// Called every frame
void AStateAgresivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tiempo += DeltaTime;
	if (tiempo >= 1) {
		PerderEnergia();
		tiempo = 0;
	}  

}

void AStateAgresivo::SetEnemigo(AEnemigoDragon* _enemigo)
{
	enemigo = _enemigo;
    PosicionInicial = enemigo->GetActorLocation();
    LimiteInicial = PosicionInicial + FVector(0, 2000, 0);
    LimiteFinal = PosicionInicial + FVector(0, -2000, 0);
}

FString AStateAgresivo::GetEstado()
{
	return "El Dragon se encuentra en estado agresivo. corre!!!!!!";
}

void AStateAgresivo::atacar()
{
    if (Jugador) {
      FVector Direccion = (Jugador->GetActorLocation() - enemigo->GetActorLocation()).GetSafeNormal();
      FVector Posicion = enemigo->GetActorLocation() + (Direccion * 30.0f);
      enemigo->SetActorLocation(Posicion);
      FRotator Rotacion = Direccion.Rotation();
      Rotacion.Pitch = 0.0f;
      Rotacion.Roll = 0.0f;
      Rotacion.Yaw > 0 ? Rotacion.Yaw = 0 : Rotacion.Yaw = 180;
      enemigo->SetActorRotation(Rotacion);
      GetWorld()->GetTimerManager().SetTimer(ataque, this, &AStateAgresivo::atacar, 0.009f, true);
    }
    if (Jugador) {
        FVector JugadorPosicion = Jugador->GetActorLocation();
        FVector PosicionEnemigo = enemigo->GetActorLocation();
        float Distancia = FVector::Dist(PosicionEnemigo, JugadorPosicion);
        if (Distancia > 1500.f) moverse();
    }
}

void AStateAgresivo::moverse()
{
    posicionActual = enemigo->GetActorLocation();
    mirar = enemigo->GetActorRotation();
    if (vigilar)
    {
        if (posicionActual.Y <= LimiteInicial.Y) {
            posicionActual.Y += incremento;
            mirar.Yaw = 0;
        }
        else vigilar = false;
    }
    else
    {
        if (posicionActual.Y >= LimiteFinal.Y) {
            posicionActual.Y -= incremento;
            mirar.Yaw = 180;
        }
        else vigilar = true;
    }
    enemigo->SetActorLocation(posicionActual);
    enemigo->SetActorRotation(mirar);
    GetWorld()->GetTimerManager().SetTimer(ataque, this, &AStateAgresivo::moverse, 0.001f, true);
    if (Jugador) {
		FVector JugadorPosicion = Jugador->GetActorLocation();
		FVector PosicionEnemigo = enemigo->GetActorLocation();
        float Distancia = FVector::Dist(PosicionEnemigo, JugadorPosicion);
		if (Distancia < 1500.f) atacar();
    }
}

void AStateAgresivo::PerderEnergia()
{
    if (enemigo->GetEnergia() >= 10) {
        enemigo->PerderEnergia();
	}
    else {
        GetWorld()->GetTimerManager().ClearTimer(ataque);
        enemigo->EstablecerEstado(enemigo->GetEstadoPasivo());
    }
}
