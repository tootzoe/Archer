// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ArcherPlayerController.generated.h"




class AArcherPlayerCameraManager;
class AArcherCharacter;
class AArcherGameMode;
class USlowTimeManager;


/**
 * 
 */
UCLASS(Blueprintable)
class ARCHER_API AArcherPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
   void Initialize();
    virtual void PreInitializeComponents() override;
    virtual void PostInitializeComponents() override;


    UPROPERTY(BlueprintReadWrite)
    bool IsPlayerUsingGamepad;



  protected:

 private:
    AArcherPlayerController();

    UPROPERTY()
    AArcherGameMode *CurrentGameMode;


    UPROPERTY()
    AArcherCharacter *ArcherCharacter;

    UPROPERTY()
    AArcherPlayerCameraManager *CameraManager;

    UPROPERTY()
    USlowTimeManager *SlowTimeManager;

    bool bIsPaused;
    FInputModeGameAndUI InputMode;

    virtual void SetupInputComponent() override;
    virtual void InitInputSystem() override;

    void OnSlowModePressed();
    void OnPausePressed();
    void SetPrecisionMode();
    void SetNormalMode();
    void SetOrbitalMode();


    };
