// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimSequence.h"

#include "CharacterAnimationSlots.h"
#include "CharacterAnimationStates.h"



#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARCHER_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
    UCharacterAnimInstance();

public:

        virtual void NativeInitializeAnimation() override;
        virtual void NativeBeginPlay() override;

    void PlayAnimationInSlot(UAnimSequence *AnimSequence , ECharacterAnimationSlots AnimationSlot);
   FORCEINLINE  void SetLocomotionState(ECharacterLocomotionState State){LocomotionState = State;}
   FORCEINLINE  void SetAttactState(ECharacterAttactState State){AttactState = State;}
   void SetOrientationType(EOrientationType otype);

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateAnimationProperties(float DeltaTime);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Movement")
    class AArcherCharacter *Character;


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Movement")
    ECharacterLocomotionState LocomotionState;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Movement")
    ECharacterAttactState AttactState;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Movement")
    float  Speed;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Movement")
    bool IsMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Movement")
    float MovementOffsetYaw;

    UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Movement")
    float LastMovementOffsetYaw;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Turn in place")
    float RootYawOffset;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Turn in place")
    float Pitch;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly , Category = "Turn in place")
    FRotator AimRotation;



    UPROPERTY(BlueprintReadOnly  )
    float DeltaTime;



    EOrientationType OrientationType;
    float RotationCurve;
    float RotationCurveLastFrame;


private:
    float CurrentCharacterYaw;
    float LastCharacterYaw;
    TMap<ECharacterAnimationSlots , FName> SlotNames;
	

    void checkMovement();
    void turnInPlace();


};


















