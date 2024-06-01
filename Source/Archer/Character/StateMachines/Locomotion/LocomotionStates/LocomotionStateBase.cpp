// Fill out your copyright notice in the Description page of Project Settings.


#include "LocomotionStateBase.h"

FLocomotionStateBase::FLocomotionStateBase(FStateMachineBase *StateMachine)
{
    this->StateMachine = (FLocomotionStateMachine*)StateMachine;
}

// FLocomotionStateBase::~FLocomotionStateBase()
// {
// }
