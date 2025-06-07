// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterMechanics.h"

#include "Kismet/GameplayStatics.h"

#include "ArchTrace.h"


#include "../Animation/CharacterAnimations.h"
#include "../../Enemies/Enemy.h"




FCharacterMechanics::FCharacterMechanics(UArchTrace *ArchTrace, UCharacterAnimations *CharacterAnimations)
{
    this->ArchTrace = ArchTrace;
    this->CharacterAnimations = CharacterAnimations;
}

void FCharacterMechanics::AutoAim()
{
    AActor *cloestTarget = GetMouseClosestTarget();
    if(!cloestTarget) return;

    ArchTrace->SetAimDirection(cloestTarget);

}

void FCharacterMechanics::AutoAimGamepad()
{
    AActor *cloestTarget = GetGamepadClosestTarget();
    if(!cloestTarget) return;

    ArchTrace->SetAimDirection(cloestTarget);
}

void FCharacterMechanics::SetAutoAimTargets() const
{
    TArray<AActor *> EnemyActors;
    TArray<AEnemy *> AliveEnemies;

    UGameplayStatics::GetAllActorsOfClass(ArchTrace->GetWorld() , AEnemy::StaticClass() , EnemyActors);

    for(int idx = EnemyActors.Num() - 1 ; idx >= 0 ; idx --){
        AEnemy *e = Cast<AEnemy , AActor>(EnemyActors[idx]);
        if(e->IsAlive())
            AliveEnemies.Add(e);
    }

    ArchTrace->SetAutoAimTargets(AliveEnemies);

}

bool FCharacterMechanics::IsThereAnyTarget() const
{
    return ArchTrace->IsThereAnyTarget();
}

void FCharacterMechanics::FreeAim() const
{
    ArchTrace->FreeAimMouse();
}

void FCharacterMechanics::FreeAimGamepad() const
{
    ArchTrace->FreeAimGamepad();
}

void FCharacterMechanics::PrecisionAim(const FVector TargetLocation) const
{
    ArchTrace->SetAimDirectionToTargetPosition(TargetLocation);
}

AActor *FCharacterMechanics::GetMouseClosestTarget() const
{
    return ArchTrace->GetMouseClosestTarget();
}

AActor *FCharacterMechanics::GetGamepadClosestTarget() const
{
    return ArchTrace->GetGamepadClosestTarget();
}

void FCharacterMechanics::DrawArrow(FTimerDelegate TimerDelegate)
{
    ArchTrace->GetWorld()->GetTimerManager().SetTimer(TimerHandle , TimerDelegate , HoldShootForPrecisionModeTime, false);
    CharacterAnimations->SetAttactState(ECharacterAttactState::Drawback);
}

void FCharacterMechanics::ReleaseArrow()
{
    StopDrawingArrow();
    CharacterAnimations->SetAttactState(ECharacterAttactState::Release);
    ArchTrace->Shoot(ProjectileClass);

    //TODO after some timer, it should go back to aiming/ normal

}

void FCharacterMechanics::StopDrawingArrow()
{
    ArchTrace->GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
    TimerHandle.Invalidate();
}

void FCharacterMechanics::InterpolateAimDirection(float DeltaTime) const
{
    ArchTrace->SetInterpolatedAimDirection(DeltaTime);
}

// FCharacterMechanics::~FCharacterMechanics()
// {
// }
