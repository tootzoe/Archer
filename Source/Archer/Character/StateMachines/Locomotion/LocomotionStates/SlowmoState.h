// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#include "LocomotionStateBase.h"

/**
 * 
 */
class  FSlowmoState : public FLocomotionStateBase
{
public:
   explicit FSlowmoState(FStateMachineBase *StateMachine) ;

    ~FSlowmoState();

    virtual void Begin() override;
    virtual void End() override;

};
