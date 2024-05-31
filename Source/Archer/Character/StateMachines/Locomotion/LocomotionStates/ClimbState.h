// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LocomotionStateBase.h"

/**
 * 
 */
class  FClimbState : public FLocomotionStateBase
{
public:
    explicit FClimbState(FStateMachineBase *StateMachin);
    ~FClimbState();

    virtual void Begin() override;
    virtual void End() override;

};
