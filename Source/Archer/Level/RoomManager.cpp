// Fill out your copyright notice in the Description page of Project Settings.

#include "RoomManager.h"

#include "Components/BoxComponent.h"


// Sets default values
ARoomManager::ARoomManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>("Root");
    RootComponent = Root;

    CameraPivot = CreateDefaultSubobject<USceneComponent>("CameraPivot");
    PlayerCollision = CreateDefaultSubobject<UBoxComponent>("PlayerCollision");

}

// Called when the game starts or when spawned
void ARoomManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoomManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

