// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CapsuleComponent.h"


#include "CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Health = MAX_HEALTH;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

void ACharacterBase::Die()
{
    OnCharacterDead.Broadcast();
    PrimaryActorTick.bCanEverTick = false;

    GetCapsuleComponent()->SetGenerateOverlapEvents(false);

}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ACharacterBase::IsAlive() const
{
    return Health > 0;
}

void ACharacterBase::Hit()
{
    Health --;

    if(!IsAlive()){
        Die();
    }
}

