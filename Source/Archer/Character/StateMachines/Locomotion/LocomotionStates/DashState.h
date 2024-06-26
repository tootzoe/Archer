// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LocomotionStateBase.h"

/**
 * 
 */
class FDashState : public FLocomotionStateBase
{
public:
    explicit FDashState(FStateMachineBase *StateMachin);
    ~FDashState();

    virtual void Begin() override;
    virtual void End() override;

};
