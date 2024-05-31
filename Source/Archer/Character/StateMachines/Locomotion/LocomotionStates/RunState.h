// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "LocomotionStateBase.h"

/**
 * 
 */
class  FRunState : public FLocomotionStateBase
{
public:
   explicit FRunState(FStateMachineBase *StateMachin);
    ~FRunState();


    virtual void Begin() override;
    virtual void End() override;

};
