// Fill out your copyright notice in the Description page of Project Settings.

#include "MechanicStateBase.h"

#include "../../../Mechanics/CharacterMechanics.h"
#include "../MechanicsStateMachine.h"





FMechanicStateBase::FMechanicStateBase(FStateMachineBase *MechanicsStateMachine) :
    FStateBase()
{
    this->MechanicsStateMachine = static_cast<FMechanicsStateMachine* >(MechanicsStateMachine);
}


void FMechanicStateBase::Begin()
{
    CharacterMechanics = MechanicsStateMachine->GetCharacterMechanics();
}





















