// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"




#include "ArcherCharacter.generated.h"

/**
 * 
 */

class USlowTimeManager;
class UArchTrace;
class UCharacterAnimations;
class AProjectile;
class FLocomotionStateMachine;
class FMechanicsStateMachine;
class FCharacterMovement;
class FCharacterMechanics;
class AArcherPlayerController;

UCLASS(config=Game)
class ARCHER_API AArcherCharacter : public ACharacterBase
{
	GENERATED_BODY()
 public:
    AArcherCharacter();
    virtual ~AArcherCharacter() override;

    void Initialize(USlowTimeManager* TimeManager);
    void DisableMovement() const;
    void EnableMovement() const;

    FRotator GetAimRotator() const;
    FRotator GetAimRotationRelativeToMovement() const;
    FORCEINLINE FCharacterMechanics *GetCharacterMechanics() const {return CharacterMechanics;}
    FORCEINLINE FCharacterMovement *GetArcherMovement() const {return ArcherMovement;}
    FORCEINLINE UCharacterAnimations *GetArcherAnimations() const {return CharacterAnimations;}
    FORCEINLINE FMechanicsStateMachine *GetMechanicsStateMachine() const {return MechanicsStateMachine;}
    FORCEINLINE AArcherPlayerController *GetPlayerController() const {return PlayerController;}



 protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Archer")
    UArchTrace *Arch;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Archer")
    UCharacterAnimations *CharacterAnimations;

    UPROPERTY(EditDefaultsOnly, Category="Archer")
    TSubclassOf<AProjectile> ProjectleClass;

    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;
    virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction &ThisTickFunction) override;



private:
    FLocomotionStateMachine *LocomotionStateMachine;
    FMechanicsStateMachine *MechanicsStateMachine;
    FCharacterMovement *ArcherMovement;
    FCharacterMechanics *CharacterMechanics;
    AArcherPlayerController *PlayerController;


    void MoveForward(const float val);
    void MoveRight( const float val);
    void StartRunning();
    void StopRunning();
    void Aim();
    void StopAim();
    void StartShoot();
    void ReleaseShoot();
    void StartFreeAim();
    void StopFreeAim();
    void PrecisionAimX(float val);
    void PrecisionAimY(float val);

	

};















