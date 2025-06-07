// Fill out your copyright notice in the Description page of Project Settings.

#include "DashState.h"


#include "../../../Animation/CharacterAnimations.h"
#include "../../../Animation/CharacterAnimationStates.h"
#include "../../../Movement/CharacterMovement.h"
#include "../../../StateMachines/Locomotion/LocomotionStateMachine.h"
#include "../../../StateMachines/Mechanics/MechanicsStateMachine.h"





FDashState::FDashState(FStateMachineBase *StateMachin)
 :  FLocomotionStateBase(StateMachin)
{

}

FDashState::~FDashState()
{
}


void FDashState::Begin()
{
    StateMachine->GetCharacterAnimations()->SetLocomotionState(ECharacterLocomotionState::Dashing);

}

void FDashState::End()
{

}
