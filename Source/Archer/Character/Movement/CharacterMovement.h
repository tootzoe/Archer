// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"




class APlayerCameraManager ;
class UCharacterMovementComponent;

/**
 * 
 */
class  FCharacterMovement
{
public:
    explicit FCharacterMovement(UCharacterMovementComponent *MovementComponent);
    ~FCharacterMovement();

    FVector GetCameraRelativeForwardVector() const;
    FVector GetCameraRelativeRightVector() const;

    void MoveForward(float val) const;
    void MoveRight(float val) const;
    void SetCameraManager(APlayerCameraManager *cm);
    void SetWalkSpeed() const;
    void SetRunSpeed() const;


   private:

    const float WalkSpeed = 500.f;
    const float RunSpeed = 800.f;

    UCharacterMovementComponent *MovementComponent;
    APlayerCameraManager *CameraManager;

    FVector GetProjectedVector(const FVector vector) const;

};
























