// Fill out your copyright notice in the Description page of Project Settings.



#include "../../../Mechanics/CharacterMechanics.h"
#include "../MechanicsStateMachine.h"


#include "MechanicStateBase.h"


FMechanicStateBase::FMechanicStateBase(FStateMachineBase *MechanicsStateMachine) :
    FStateBase()
{
    this->MechanicsStateMachine = static_cast<FMechanicsStateMachine* >(MechanicsStateMachine);
}


void FMechanicStateBase::Begin()
{
    CharacterMechanics = MechanicsStateMachine->GetCharacterMechanics();
}





















