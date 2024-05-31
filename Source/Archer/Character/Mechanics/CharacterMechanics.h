// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TimerManager.h"

#include "../../Weapons/Projectile.h"




#include "CoreMinimal.h"


class UArchTrace;
class UCharacterAnimations;

/**
 * 
 */
class  FCharacterMechanics
{
public:
    FCharacterMechanics(UArchTrace *ArchTrace, UCharacterAnimations *CharacterAnimations);
   // ~FCharacterMechanics();

    void AutoAim();
    void AutoAimGamepad();
    void SetAutoAimTargets() const;
    bool IsThereAnyTarget() const;

    void FreeAim() const;
    void FreeAimGamepad() const;
    void PrecisionAim(const FVector TargetLocation) const;
    AActor *GetMouseClosestTarget() const;
    AActor *GetGamepadClosestTarget() const;
    void DrawArrow(FTimerDelegate TimerDelegate);
    void ReleaseArrow();
    void StopDrawingArrow();



    void InterpolateAimDirection(float DeltaTime) const;

    FORCEINLINE void SetProjectile(TSubclassOf<AProjectile> projectileClass){this->ProjectileClass = projectileClass;}

private:

    UArchTrace *ArchTrace;
    TSubclassOf<AProjectile> ProjectileClass;
    UCharacterAnimations *CharacterAnimations;

    FTimerHandle TimerHandle;
    float HoldShootForPrecisionModeTime = 0.25f;


};



















