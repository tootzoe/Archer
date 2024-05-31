// Fill out your copyright notice in the Description page of Project Settings.



#include "../../../Animation/CharacterAnimations.h"
#include "../../../Animation/CharacterAnimationStates.h"
#include "../../../Movement/CharacterMovement.h"
#include "../../../StateMachines/Locomotion/LocomotionStateMachine.h"
#include "../../../StateMachines/Mechanics/MechanicsStateMachine.h"



#include "ClimbState.h"



FClimbState::FClimbState(FStateMachineBase *StateMachin)
 :  FLocomotionStateBase(StateMachin)
{

}

FClimbState::~FClimbState()
{
}


void FClimbState::Begin()
{
    StateMachine->GetCharacterAnimations()->SetLocomotionState(ECharacterLocomotionState::Climbing);

}

void FClimbState::End()
{

}








