// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArcherCameraActorBase.h"
#include "OrbitalCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class ARCHER_API AOrbitalCameraActor : public AArcherCameraActorBase
{
	GENERATED_BODY()

  public:

    explicit AOrbitalCameraActor();

    void SetPivotPoint(USceneComponent *PivotPoint);


    virtual void RotateCameraLeftRight(float) override;

protected:

    virtual void BeginPlay() override;
    virtual void RotateCameraUpDown(float) override;

    virtual void SetupPlayerInputComponent() override;
    void CorrectRollRotation();


  UPROPERTY(EditDefaultsOnly)
  float RotationSpeed = 1.f;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Zoom = 1000.f;


private:
   void LookAtRoot();

	

   };


