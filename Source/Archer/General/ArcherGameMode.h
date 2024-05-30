// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcherGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ARCHER_API AArcherGameMode : public AGameModeBase
{
	GENERATED_BODY()
    AArcherGameMode();
public:

enum GameplayMode {
    Normal,
    Orbital,
    Precision,
    Menu
};
    GameplayMode CurrentGameplayMode;

    FORCEINLINE GameplayMode GetCurrentGameplayMode() const {return CurrentGameplayMode;}
    FORCEINLINE void SetCurrentGameplayMode(GameplayMode m)  {  CurrentGameplayMode = m;}

protected:
    void BeforeStartPlay();
    virtual void StartPlay() override;
    void AfterStartPlay();


private:
    UPROPERTY()
    class AArcherPlayerController* PlayerController;
	

    };
