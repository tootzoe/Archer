// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArcherCameraActorBase.h"
#include "PrecisionCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class ARCHER_API APrecisionCameraActor : public AArcherCameraActorBase
{
	GENERATED_BODY()


protected:
    virtual void BeginPlay() override;

    virtual void  RotateCameraLeftRight(float) override;
    virtual void   RotateCameraUpDown(float) override;
};
