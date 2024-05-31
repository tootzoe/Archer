// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../../StateBase.h"


class FMechanicsStateMachine;
class FStateMachineBase;
/**
 * 
 */
class  FMechanicStateBase : public FStateBase
{
public:
    explicit FMechanicStateBase(FStateMachineBase *MechanicsStateMachine);


    virtual void Begin() override;
    virtual void Tick(float DeltaTime) = 0;

protected:
    FMechanicsStateMachine *MechanicsStateMachine;
    class FCharacterMechanics *CharacterMechanics;

};


















