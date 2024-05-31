// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../StateMachineBase.h"

class FMechanicsStateMachine;


/**
 * 
 */
class  FLocomotionStateMachine : public FStateMachineBase
{
public:
    explicit FLocomotionStateMachine(AArcherCharacter *archer);
    ~FLocomotionStateMachine();

    MovementSignature MoveForwardDelegate;
    MovementSignature MoveRightDelegate;
    ActionSignature StartRunDelegate;
    ActionSignature StopRunDelegate;
    ActionSignature StartFreeAimDelegate;
    ActionSignature StopFreeAimDelegate;
    ActionSignature DashDelegate;
    ActionSignature StartClimbDelegate;
    ActionSignature StopClimbDelegate;


    void SetWalkState();
    void SetRunState();
    void SetDashState();
    void SetJumpState();
    void SetClimbState();
    void SetSlowmoState();

    FMechanicsStateMachine *GetMechanicsStateMachine() const;

protected:
    virtual void SetSpecificState() override {;}

};
