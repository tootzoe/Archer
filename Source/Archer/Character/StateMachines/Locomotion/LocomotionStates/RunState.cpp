// Fill out your copyright notice in the Description page of Project Settings.


#include "../../../Animation/CharacterAnimations.h"
#include "../../../Animation/CharacterAnimationStates.h"
#include "../../../Movement/CharacterMovement.h"
#include "../../../StateMachines/Locomotion/LocomotionStateMachine.h"
#include "../../../StateMachines/Mechanics/MechanicsStateMachine.h"



#include "RunState.h"


FRunState::FRunState(FStateMachineBase *StateMachin)
    :  FLocomotionStateBase(StateMachin)
{

}

FRunState::~FRunState()
{
}


void FRunState::Begin()
{
    StateMachine->GetCharacterAnimations()->SetLocomotionState(ECharacterLocomotionState::Running);
    StateMachine->GetCharacterMovement()->SetRunSpeed();
    StateMachine->GetMechanicsStateMachine()->SetEmptyState();

    StateMachine->MoveForwardDelegate.AddRaw(StateMachine->GetCharacterMovement(), &FCharacterMovement::MoveForward);
    StateMachine->MoveRightDelegate.AddRaw(StateMachine->GetCharacterMovement(), &FCharacterMovement::MoveRight);
    StateMachine->StartRunDelegate.AddRaw(StateMachine , &FLocomotionStateMachine::SetWalkState);


}

void FRunState::End()
{
    StateMachine->MoveForwardDelegate.Clear();
    StateMachine->MoveRightDelegate.Clear();
    StateMachine->StartRunDelegate.Clear();
}
