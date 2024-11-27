// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoDragon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "StateAgresivo.h"
#include "StatePasivo.h"

// Sets default values
AEnemigoDragon::AEnemigoDragon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/FourEvilDragonsHP/Meshes/DragonTheUsurper/DragonTheUsurperSK.DragonTheUsurperSK'"));
    if (MeshAsset.Succeeded())
    {
        SkeletalMesh->SetSkeletalMesh(MeshAsset.Object);
    }
    SkeletalMesh->SetupAttachment(RootComponent);
    SkeletalMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    SkeletalMesh->SetRelativeLocation(FVector(0.0f, 0.f, -400.0f));
    // Cargar la animaci�n
    static ConstructorHelpers::FObjectFinder<UAnimSequence> AnimationAsset(TEXT("AnimSequence'/Game/FourEvilDragonsHP/Animations/DragonTheUsurper/FlyForwardAnim.FlyForwardAnim'"));
    if (AnimationAsset.Succeeded())
    {
        MyAnimationAsset = AnimationAsset.Object;
    }
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;

}

// Called when the game starts or when spawned
void AEnemigoDragon::BeginPlay()
{
	Super::BeginPlay();
    if (MyAnimationAsset && SkeletalMesh)
    {
        SkeletalMesh->PlayAnimation(MyAnimationAsset, true);
    }
    EstadoPasivo = GetWorld()->SpawnActor<AStatePasivo>(AStatePasivo::StaticClass());
    EstadoPasivo->SetEnemigo(this);
    EstadoAgresivo = GetWorld()->SpawnActor<AStateAgresivo>(AStateAgresivo::StaticClass());
    EstadoAgresivo->SetEnemigo(this);
}

// Called every frame
void AEnemigoDragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// state
void AEnemigoDragon::InicializarEnemigo(int _energia)
{
	energia = _energia;
	energia>=35 ? Estado = EstadoAgresivo : Estado = EstadoPasivo;
}

void AEnemigoDragon::EstablecerEstado(IIState* _estado)
{
	Estado = _estado;
	Ataque();
}

void AEnemigoDragon::Ataque()
{
	if(Estado) Estado->atacar();
}

void AEnemigoDragon::Moverse()
{
	if(Estado) Estado->moverse();
}
