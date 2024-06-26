// Fill out your copyright notice in the Description page of Project Settings.

#include "../../../Animation/CharacterAnimations.h"
#include "../../../Mechanics/CharacterMechanics.h"
#include "../MechanicsStateMachine.h"


#include "ShieldState.h"



void FShieldState::Begin()
{
    FMechanicStateBase::Begin();

    MechanicsStateMachine->GetCharacterAnimations()
            ->SetOrientationType(EOrientationType::AimDirection);


}

void FShieldState::End()
{

}

void FShieldState::Tick(float DeltaTime)
{
    CharacterMechanics->InterpolateAimDirection(DeltaTime);
}

















