// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "ArcherGameInstance.h"
#include "ArcherGameState.h"
#include "../Player/ArcherPlayerController.h"




#include "ArcherGameMode.h"



AArcherGameMode::AArcherGameMode()
{
    PlayerControllerClass = AArcherPlayerController::StaticClass();
    GameStateClass = AArcherGameState::StaticClass();

}

void AArcherGameMode::BeforeStartPlay()
{
    GetWorld()->bIsCameraMoveableWhenPaused = true;
}

void AArcherGameMode::StartPlay()
{
    BeforeStartPlay();
    Super::StartPlay();
    AfterStartPlay();
}

void AArcherGameMode::AfterStartPlay()
{
    PlayerController = Cast<AArcherPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
    PlayerController->Initialize();
}
