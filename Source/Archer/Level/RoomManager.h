// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomManager.generated.h"

UCLASS()
class ARCHER_API ARoomManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoomManager();

    virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USceneComponent *Root;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    USceneComponent *CameraPivot;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    class UBoxComponent *PlayerCollision;




};
