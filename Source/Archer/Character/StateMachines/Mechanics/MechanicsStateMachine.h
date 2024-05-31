// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "../StateMachineBase.h"





/**
 * 
 */
class FMechanicsStateMachine : public FStateMachineBase
{


public:
   explicit  FMechanicsStateMachine(AArcherCharacter *ArcherCharacter);
    ~FMechanicsStateMachine();

    ActionSignature StartAimingDelegate;
    ActionSignature StopAimingDelegate;
    ActionSignature StartShootingDelegate;
    ActionSignature StoptShootingDelegate;
    ActionSignature StartFreeAimDelegate;
    ActionSignature StopFreeAimDelegate;

    MovementSignature AimXValueDelegate;
    MovementSignature AimYValueDelegate;

    void Tick(float DeltaTime);

    void SetEmptyState();
    void SetAimReadyState();
    void SetFreeAimState();
    void SetAutoAimState();
    void SetPrecisionAimState();


protected:
    virtual void SetSpecificState() override;


private:
    class FMechanicStateBase* MechanicState;

};
















