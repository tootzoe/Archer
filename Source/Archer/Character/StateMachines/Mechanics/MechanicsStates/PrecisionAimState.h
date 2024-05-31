// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MechanicStateBase.h"



/**
 * 
 */
class  FPrecisionAimState : public FMechanicStateBase
{
public:
    FPrecisionAimState(FStateMachineBase *MechanicStateMachine) :
        FMechanicStateBase(MechanicStateMachine)
    {}

    virtual void Begin() override;
    virtual void End() override;
    virtual void Tick(float DeltaTime) override;

    private:
    class AActor *TargetActor;
    FVector Offset;

    const float OffsetInputRelation = 5.f;

    void SetPrecisionXOffset(float val);
    void SetPrecisionYOffset(float val);
    void ReleaseAndSetAutoAimState(  ) const;


};
