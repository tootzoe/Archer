// Fill out your copyright notice in the Description page of Project Settings.

#include "MechanicsStateMachine.h"

#include "MechanicsStates/AimReadyState.h"
#include "MechanicsStates/AutoAimState.h"
#include "MechanicsStates/EmptyState.h"
#include "MechanicsStates/FreeAimState.h"
#include "MechanicsStates/PrecisionAimState.h"






FMechanicsStateMachine::FMechanicsStateMachine(AArcherCharacter *ArcherCharacter)
    : FStateMachineBase(ArcherCharacter)
{
    State = new FAimReadyState(this);
    FMechanicsStateMachine::SetSpecificState();
}

FMechanicsStateMachine::~FMechanicsStateMachine()
{

}

void FMechanicsStateMachine::Tick(float DeltaTime)
{
     MechanicState->Tick(DeltaTime);
}

void FMechanicsStateMachine::SetEmptyState()
{
    SetState<FEmptyState>();
}

void FMechanicsStateMachine::SetAimReadyState()
{
    SetState<FAimReadyState>();
}

void FMechanicsStateMachine::SetFreeAimState()
{
    SetState<FFreeAimState>();
}

void FMechanicsStateMachine::SetAutoAimState()
{
    SetState<FAutoAimState>();
}

void FMechanicsStateMachine::SetPrecisionAimState()
{
    SetState<FPrecisionAimState>();
}


void FMechanicsStateMachine::SetSpecificState()
{
    MechanicState = static_cast<FMechanicStateBase*>(State);
}
