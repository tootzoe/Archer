// Fill out your copyright notice in the Description page of Project Settings.

#include "../../../Animation/CharacterAnimations.h"
#include "../../../Animation/CharacterAnimationStates.h"
#include "../../../Movement/CharacterMovement.h"
#include "../../../StateMachines/Locomotion/LocomotionStateMachine.h"
#include "../../../StateMachines/Mechanics/MechanicsStateMachine.h"


#include "WalkState.h"


FWalkState::FWalkState(FStateMachineBase *StateMachin) :
    FLocomotionStateBase(StateMachin)
{


}

FWalkState::~FWalkState()
{

}

void FWalkState::Begin()
{
    StateMachine->GetCharacterAnimations()->SetLocomotionState(ECharacterLocomotionState::Normal);
    StateMachine->GetCharacterMovement()->SetWalkSpeed();
    StateMachine->GetMechanicsStateMachine()->SetAimReadyState();

    StateMachine->MoveForwardDelegate.AddRaw(StateMachine->GetCharacterMovement(), &FCharacterMovement::MoveForward);
    StateMachine->MoveRightDelegate.AddRaw(StateMachine->GetCharacterMovement(), &FCharacterMovement::MoveRight);
    StateMachine->StartRunDelegate.AddRaw(StateMachine , &FLocomotionStateMachine::SetRunState);


    StateMachine->GetMechanicsStateMachine()->StartAimingDelegate.AddRaw(StateMachine->GetMechanicsStateMachine(),
                                                                         &FMechanicsStateMachine::SetAimReadyState);

}

void FWalkState::End()
{
    StateMachine->MoveForwardDelegate.Clear();
    StateMachine->MoveRightDelegate.Clear();
    StateMachine->StartRunDelegate.Clear();
    StateMachine->GetMechanicsStateMachine()->StopAimingDelegate.Clear();

}




















