// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbitalCameraActor.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"



#include "ArcherPlayerCameraManager.h"










AOrbitalCameraActor::AOrbitalCameraActor()
{

}

void AOrbitalCameraActor::SetPivotPoint(USceneComponent *PivotPoint)
{
    SetActorLocation(PivotPoint->GetComponentLocation());

}

void AOrbitalCameraActor::BeginPlay()
{
    Super::BeginPlay();




    // AArcherPlayerCameraManager* CameraManager = Cast<AArcherPlayerCameraManager>(
    // UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0) );

    // CameraManager->AddOrbitalCameraReference(this);
    //  CameraManager->SetViewTarget(this);
    // CameraManager->SetCurrentCamera(this);

    // Camera->SetRelativeLocation(FVector(-Zoom , 0.f , Zoom));
    // LookAtRoot();
    // RotateCameraLeftRight(45.f);



}

void AOrbitalCameraActor::RotateCameraUpDown(float val)
{
    if(val == 0.f) return;

    const FVector ForwardVector = Camera->GetForwardVector();
    const FVector UpVector = Camera->GetUpVector();
    FVector ProjectedForward = UKismetMathLibrary::ProjectVectorOnToPlane(ForwardVector , UpVector);
    ProjectedForward.Normalize();

    FVector RotationVector = GetActorRotation().Vector();
    RotationVector += ProjectedForward / 100.f * val * RotationSpeed;

    FRotator Rotation = GetActorRotation();
    Rotation.Pitch -= val * RotationSpeed;
    SetActorRelativeRotation(Rotation);
    CorrectRollRotation();

}

void AOrbitalCameraActor::RotateCameraLeftRight(float val)
{
    if(val == 0.f ) return;

    FRotator Rotatino = GetActorRotation();
    Rotatino.Yaw -= val * RotationSpeed;
    SetActorRelativeRotation(Rotatino);

    CorrectRollRotation();

}




void AOrbitalCameraActor::SetupPlayerInputComponent()
{
    Super::SetupPlayerInputComponent();





}

void AOrbitalCameraActor::CorrectRollRotation()
{

    FRotator Rotation = GetActorRotation();
    Rotation.Roll = 0.f;
    SetActorRotation(Rotation);

}

void AOrbitalCameraActor::LookAtRoot()
{
    FVector RootDirection = -Camera->GetRelativeLocation();
    RootDirection.Normalize();
    Camera->SetRelativeRotation(RootDirection.Rotation());

}












