// Fill out your copyright notice in the Description page of Project Settings.


#include "EmptyState.h"


#include "Engine.h"

#include "../../../Animation/CharacterAnimationStates.h"
#include "../../../Animation/CharacterAnimations.h"
#include "../../../Mechanics/CharacterMechanics.h"
#include "../MechanicsStateMachine.h"






void FEmptyState::Begin()
{
    MechanicsStateMachine->GetCharacterAnimations()->SetAttactState(ECharacterAttactState::NotAiming);
    MechanicsStateMachine->GetCharacterAnimations()->SetOrientationType(EOrientationType::Movement);

}

void FEmptyState::End()
{

}

void FEmptyState::Tick(float DeltaTime)
{
    GEngine->AddOnScreenDebugMessage(0 , -1 , FColor::Green , "EmptyState....");
}


















