// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine.h"

#include "../../../Animation/CharacterAnimations.h"
#include "../../../Mechanics/CharacterMechanics.h"
#include "../MechanicsStateMachine.h"



#include "AimReadyState.h"



void FAimReadyState::Begin()
{
    MechanicsStateMachine->StartAimingDelegate.AddRaw(this, &FAimReadyState::SetAimState);
    MechanicsStateMachine->StartFreeAimDelegate.AddRaw(this, &FAimReadyState::SetFreeAimExpected);
    MechanicsStateMachine->StopFreeAimDelegate.AddRaw(this, &FAimReadyState::SetFreeAimNotExpected);

    MechanicsStateMachine->GetCharacterAnimations()->SetOrientationType(EOrientationType::Movement);
}

void FAimReadyState::End()
{
    MechanicsStateMachine->StartAimingDelegate.Clear();
    MechanicsStateMachine->StartFreeAimDelegate.Clear();
    MechanicsStateMachine->StopFreeAimDelegate.Clear();

}

void FAimReadyState::Tick(float DeltaTime)
{
    GEngine->AddOnScreenDebugMessage(0 , -1 , FColor::Green , "AimReadyState....");
}

void FAimReadyState::SetAimState() const
{
    if(IsFreeAimExpected){
        MechanicsStateMachine->SetFreeAimState();
    }else
        MechanicsStateMachine->SetAutoAimState();

}

void FAimReadyState::SetFreeAimExpected()
{
    IsFreeAimExpected = true;
}

void FAimReadyState::SetFreeAimNotExpected()
{
    IsFreeAimExpected = false;
}
