// Fill out your copyright notice in the Description page of Project Settings.



#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"



#include "ArcherCameraActorBase.h"

// Sets default values
AArcherCameraActorBase::AArcherCameraActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

    Camera ->SetupAttachment(RootComponent);

    PrimaryActorTick.bTickEvenWhenPaused = true;

    //UE_LOG(LogTemp , Warning , TEXT(" f= %f") , t);

}

// Called when the game starts or when spawned
void AArcherCameraActorBase::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->bIsCameraMoveableWhenPaused = true;

    SetupPlayerInputComponent();

}

void AArcherCameraActorBase::SetupPlayerInputComponent()
{

}

// Called every frame
void AArcherCameraActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

