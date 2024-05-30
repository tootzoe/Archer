// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Character/CharacterBase.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class ARCHER_API AEnemy : public ACharacterBase
{
	GENERATED_BODY()

 public:
     AEnemy();
    virtual void Tick(float DeltaSeconds) override;


   // AActor interface
   protected:
   virtual void BeginPlay() override;



// ACharacterBase interface
private:
    virtual void Die() override;
};
