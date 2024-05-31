// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MechanicStateBase.h"

/**
 * 
 */
class   FAimReadyState : public FMechanicStateBase
{
public:
    FAimReadyState(FStateMachineBase *MechanicStateMachine) :
        FMechanicStateBase(MechanicStateMachine)
    {}


    virtual void Begin() override;
    virtual void End() override;
    virtual void Tick(float DeltaTime) override;

private:
    bool IsFreeAimExpected = false;

    void SetAimState() const;
    void SetFreeAimExpected();
    void SetFreeAimNotExpected();


};
