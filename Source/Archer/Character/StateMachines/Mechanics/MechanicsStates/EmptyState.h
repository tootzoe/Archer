// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MechanicStateBase.h"

/**
 * 
 */
class   FEmptyState : public FMechanicStateBase
{
public:
    FEmptyState(FStateMachineBase *MechanicStateMachine) :
        FMechanicStateBase(MechanicStateMachine)
    {}


    virtual void Begin() override;
    virtual void End() override;
    virtual void Tick(float DeltaTime) override;

};
