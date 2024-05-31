// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../../StateBase.h"

class FLocomotionStateMachine;
class  FStateMachineBase;
/**
 * 
 */
class  FLocomotionStateBase : FStateBase
{
public:
   explicit FLocomotionStateBase(  FStateMachineBase* StateMachine);
    ~FLocomotionStateBase();

protected:
     FLocomotionStateMachine *StateMachine;
};
