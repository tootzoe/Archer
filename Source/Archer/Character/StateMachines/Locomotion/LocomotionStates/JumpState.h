// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LocomotionStateBase.h"

/**
 * 
 */
class FJumpState : FLocomotionStateBase
{
public:
    explicit FJumpState(FStateMachineBase *StateMachin);

    ~FJumpState();


    virtual void Begin() override;
    virtual void End() override;
};
