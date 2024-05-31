// Fill out your copyright notice in the Description page of Project Settings.



#include "../ArcherCharacter.h"
#include "../../Player/ArcherPlayerController.h"




#include "StateMachineBase.h"


FStateMachineBase::FStateMachineBase(AArcherCharacter *ArcherCharacter)
{
    this->ArcherCharacter = ArcherCharacter;
}

FCharacterMovement *FStateMachineBase::GetCharacterMovement() const
{
    return ArcherCharacter->GetArcherMovement();
}

FCharacterMechanics *FStateMachineBase::GetCharacterMechanics() const
{
    return ArcherCharacter->GetCharacterMechanics();
}

UCharacterAnimations *FStateMachineBase::GetCharacterAnimations() const
{
    return ArcherCharacter->GetArcherAnimations();
}

UWorld *FStateMachineBase::GetWorld() const
{
    return ArcherCharacter->GetWorld();
}

bool FStateMachineBase::IsPlayerUsingGamepad() const
{
    return ArcherCharacter->GetPlayerController()->IsPlayerUsingGamepad;
}
