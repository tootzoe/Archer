// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimations.h"

#include "CharacterAnimInstance.h"




// Sets default values for this component's properties
UCharacterAnimations::UCharacterAnimations()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterAnimations::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCharacterAnimations::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
}

void UCharacterAnimations::Initialize(UCharacterAnimInstance *AnimInstance)
{
    AnimaInstance = AnimInstance;
}

void UCharacterAnimations::SetLocomotionState(ECharacterLocomotionState State) const
{
    if(!AnimaInstance) return;
     AnimaInstance->SetLocomotionState(State);
}

void UCharacterAnimations::SetAttactState(ECharacterAttactState State) const
{
    if(!AnimaInstance) return;
     AnimaInstance->SetAttactState(State);
}

void UCharacterAnimations::SetOrientationType(EOrientationType OrientaionType)
{
    if(!AnimaInstance) return;
     AnimaInstance->SetOrientationType(OrientaionType);
}



















