// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSystem.h"


#include "Kismet/GameplayStatics.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"





// Sets default values
AWaveSystem::AWaveSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveSystem::BeginPlay()
{
	Super::BeginPlay();

    // EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

    // InputComponent->BindAction("NextWave", IE_Pressed, this, &AWaveSystem::StartNextWave);


}

void AWaveSystem::StartNextWave()
{
    UWorld *World = GetWorld();
    const FActorSpawnParameters SpawnParams;

    for(AActor *a : SpawnLocations){
         World->SpawnActor<AEnemy>(EnemyClass , a->GetActorLocation() , a->GetActorRotation() , SpawnParams);
        // UAIBlueprintHelperLibrary::SpawnAIFromClass(GetWorld(), EnemyClass , nullptr , a->GetActorLocation(),
        //                                             a->GetActorRotation());
    }


}




// Called every frame
void AWaveSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




























