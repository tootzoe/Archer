// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


#include "Camera/PlayerCameraManager.h"
#include "GameFramework/CharacterMovementComponent.h"





#include "CharacterMovement.h"

FCharacterMovement::FCharacterMovement(UCharacterMovementComponent *m)
{
    MovementComponent = m;

    MovementComponent->bOrientRotationToMovement = true;
    MovementComponent->RotationRate = FRotator(0.f , 540.f, 0.f);
    MovementComponent->JumpZVelocity = 1000.f;


}

FCharacterMovement::~FCharacterMovement()
{
}

FVector FCharacterMovement::GetCameraRelativeForwardVector() const
{
    const FVector vec = CameraManager->GetActorForwardVector();
    return GetProjectedVector(vec);
}

FVector FCharacterMovement::GetCameraRelativeRightVector() const
{
    const FVector vec = CameraManager->GetActorRightVector();
    return GetProjectedVector(vec);
}

void FCharacterMovement::MoveForward(float val) const
{
    FVector ProjectedVector = GetCameraRelativeForwardVector();
    MovementComponent->AddInputVector(ProjectedVector * val);
}

void FCharacterMovement::MoveRight(float val) const
{
    const FVector ProjectedVector = GetCameraRelativeRightVector();
    MovementComponent->AddInputVector(ProjectedVector * val);
}

void FCharacterMovement::SetCameraManager(APlayerCameraManager *cm)
{
    CameraManager = cm;
}

void FCharacterMovement::SetWalkSpeed() const
{
    MovementComponent->MaxWalkSpeed = WalkSpeed;
}

void FCharacterMovement::SetRunSpeed() const
{
    MovementComponent->MaxWalkSpeed = RunSpeed;
}

FVector FCharacterMovement::GetProjectedVector(const FVector vector) const
{
    FVector ProjectedVector = UKismetMathLibrary::ProjectVectorOnToPlane(vector, FVector::UpVector );
    ProjectedVector.Normalize();
    return ProjectedVector;
}
