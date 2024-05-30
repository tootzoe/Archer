// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActionValue.h"

#include "ArcherCameraActorBase.generated.h"

#ifdef USE_QTCREATOR
#define UCLASS()
#define PURE_VIRTUAL
#endif

UCLASS()
class ARCHER_API AArcherCameraActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArcherCameraActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


    virtual void SetupPlayerInputComponent();
    virtual void RotateCameraLeftRight(float) PURE_VIRTUAL(AArcherCameraActorBase::RotateCameraLeftRight) ;
    virtual void RotateCameraUpDown(float) PURE_VIRTUAL(AArcherCameraActorBase::RotateCameraUpDown) ;


    UPROPERTY(VisibleAnywhere)
    class UCameraComponent *Camera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};










