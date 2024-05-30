// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterDeadSignature);


UCLASS(Abstract)
class ARCHER_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

    virtual void Tick(float DeltaTime) override;

// Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable)
    bool IsAlive() const;

    virtual void Hit();

    UPROPERTY(BlueprintAssignable)
    FCharacterDeadSignature OnCharacterDead;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void Die();


    protected:
    int Health;

private:
    const int MAX_HEALTH = 1;


};
