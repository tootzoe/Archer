// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LocomotionStateBase.h"

/**
 * 
 */
class  FWalkState : public FLocomotionStateBase
{
public:
    explicit FWalkState(FStateMachineBase *StateMachin);
    ~FWalkState();

    virtual void Begin() override;
    virtual void End() override;

};
