// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"


#include "Components/CapsuleComponent.h"



AEnemy::AEnemy()
{
    PrimaryActorTick.bCanEverTick = true;

    bUseControllerRotationYaw= true;

}
void AEnemy::BeginPlay()
{
    Super::BeginPlay();
}



void AEnemy::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void AEnemy::Die()
{
    Super::Die();

    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

    if(Controller){
        Controller->UnPossess();
    }
}
