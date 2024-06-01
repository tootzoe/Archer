// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../../Enemies/Enemy.h"


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaveSystem.generated.h"




UCLASS()
class ARCHER_API AWaveSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaveSystem();

    UPROPERTY(EditAnywhere , BlueprintReadWrite)
    TArray<AActor*> SpawnLocations;

    virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void StartNextWave();

   UPROPERTY(EditDefaultsOnly)
   TSubclassOf<AEnemy> EnemyClass;



};
