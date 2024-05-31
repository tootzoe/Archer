// Fill out your copyright notice in the Description page of Project Settings.



#include "../../../Animation/CharacterAnimations.h"
#include "../../../Animation/CharacterAnimationStates.h"
#include "../../../Movement/CharacterMovement.h"
#include "../../../StateMachines/Locomotion/LocomotionStateMachine.h"
#include "../../../StateMachines/Mechanics/MechanicsStateMachine.h"



#include "JumpState.h"



FJumpState::FJumpState(FStateMachineBase *StateMachin)
    : FLocomotionStateBase(StateMachin)
{

}

FJumpState::~FJumpState()
{
}


void FJumpState::Begin()
{
    StateMachine->GetCharacterAnimations()->SetLocomotionState(ECharacterLocomotionState::Jumping);

}

void FJumpState::End()
{
    StateMachine->GetCharacterAnimations()->SetLocomotionState(ECharacterLocomotionState::Normal);

}







