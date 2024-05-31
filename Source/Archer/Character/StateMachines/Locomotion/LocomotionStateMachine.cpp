// Fill out your copyright notice in the Description page of Project Settings.


#include "LocomotionStateMachine.h"

#include "../../ArcherCharacter.h"
#include "LocomotionStates/ClimbState.h"
#include "LocomotionStates/DashState.h"
#include "LocomotionStates/JumpState.h"
#include "LocomotionStates/RunState.h"
#include "LocomotionStates/SlowmoState.h"
#include "LocomotionStates/WalkState.h"


FLocomotionStateMachine::FLocomotionStateMachine(AArcherCharacter *archer)
    : FStateMachineBase(archer)
{
    ArcherCharacter = archer;
    State = (FStateBase*)( new FWalkState(this));
}

FLocomotionStateMachine::~FLocomotionStateMachine()
{
    delete State;
}

void FLocomotionStateMachine::SetWalkState()
{
    SetState<FWalkState>();
}

void FLocomotionStateMachine::SetRunState()
{
SetState<FRunState>();
}

void FLocomotionStateMachine::SetDashState()
{
SetState<FDashState>();
}

void FLocomotionStateMachine::SetJumpState()
{
SetState<FJumpState>();
}

void FLocomotionStateMachine::SetClimbState()
{
SetState<FClimbState>();
}

void FLocomotionStateMachine::SetSlowmoState()
{
    SetState<FSlowmoState>();
}

FMechanicsStateMachine *FLocomotionStateMachine::GetMechanicsStateMachine() const
{
    return ArcherCharacter->GetMechanicsStateMachine();
}
