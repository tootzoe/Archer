// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"

#include "OrbitalCameraActor.h"

#include "ArcherPlayerCameraManager.generated.h"

/**
 * 
 */


#ifdef USE_QTCREATOR
#define UCLASS()
#define PURE_VIRTUAL
#endif

class AArcherCameraActorBase;

UCLASS()
class ARCHER_API AArcherPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

    explicit AArcherPlayerCameraManager();

public:
    virtual void BeginPlay() override;

    FORCEINLINE void AddOrbitalCameraReference(AOrbitalCameraActor *c){OrbitalCamera = c;}
    FORCEINLINE void AddPrecisionCameraReference(AOrbitalCameraActor *c){PrecisionCamera = c;}

    void Initialize(class USlowTimeManager* TimeManager);
    void SetCurrentCamera(AArcherCameraActorBase *Camera);
    void SetPrecisionCameraView();
    void SetOrbitalCameraView();
    void SetNormalCameraView();

    UFUNCTION(BlueprintCallable)
    void SetOrbitalCameraPivotPoint(USceneComponent *PivotPoint){OrbitalCamera->SetPivotPoint(PivotPoint);}

    void RotateLeft();
    void RotateRight();



private:
    UPROPERTY()
    class AOrbitalCameraActor* OrbitalCamera;

    UPROPERTY()
    AArcherCameraActorBase* PrecisionCamera;
    UPROPERTY()
    AArcherCameraActorBase* CurrentCamera;
    UPROPERTY()
    FViewTargetTransitionParams  TransitionParams;


    void EnableCurrentCameraInput();
    void DisableCurrentCameraInput();




	
};
