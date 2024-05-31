// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../../../StateMachines/StateMachineBase.h"


#include "MechanicStateBase.h"

/**
 * 
 */
class   FAutoAimState : public FMechanicStateBase
{
public:
    FAutoAimState(FStateMachineBase *MechanicStateMachine) :
        FMechanicStateBase(MechanicStateMachine)
    {}


    virtual void Begin() override;
    virtual void End() override;
    virtual void Tick(float DeltaTime) override;

private:

    ActionSignature TickDelegate;

    void DrawArrowAndStartPrecisionCount();



};
