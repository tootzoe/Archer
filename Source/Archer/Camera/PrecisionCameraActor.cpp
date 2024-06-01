// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"

#include "ArcherPlayerCameraManager.h"


#include "PrecisionCameraActor.h"


void APrecisionCameraActor::BeginPlay()
{
    Super::BeginPlay();

    AArcherPlayerCameraManager *CameraManager = Cast<AArcherPlayerCameraManager>(
      UGameplayStatics::GetPlayerCameraManager(GetWorld() , 0)
    );

     CameraManager->AddPrecisionCameraReference(this);

}

void APrecisionCameraActor::RotateCameraLeftRight(float)
{

}

void APrecisionCameraActor::RotateCameraUpDown(float)
{

}
