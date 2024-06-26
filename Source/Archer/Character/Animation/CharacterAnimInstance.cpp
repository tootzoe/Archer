// Fill out your copyright notice in the Description page of Project Settings.



#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"


#include "../ArcherCharacter.h"





#include "../../Utilities/Debug.h"

#include "CharacterAnimInstance.h"



UCharacterAnimInstance::UCharacterAnimInstance()
{
    AimRotation = FRotator(90, 0,0);
    SlotNames.Add(ECharacterAnimationSlots::FullBody , TEXT("FullBody"));
    SlotNames.Add(ECharacterAnimationSlots::UpperBody, TEXT("UpperBody"));

}

void UCharacterAnimInstance::NativeInitializeAnimation()
{
    //Super::NativeInitializeAnimation();
    Character = Cast<AArcherCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeBeginPlay()
{
    Super::NativeBeginPlay();
}

void UCharacterAnimInstance::PlayAnimationInSlot(UAnimSequence *AnimSequence, ECharacterAnimationSlots AnimationSlot)
{
    PlaySlotAnimationAsDynamicMontage(AnimSequence,SlotNames[AnimationSlot]);
}

void UCharacterAnimInstance::SetOrientationType(EOrientationType otype)
{
    OrientationType = otype;
    if(otype == EOrientationType::Movement){
   //     Character->GetCharacterMovement->bOrientRotationToMovement = true;

        MovementOffsetYaw = LastMovementOffsetYaw = 0;
        CurrentCharacterYaw = LastCharacterYaw = 0;
        RootYawOffset = 0.f;
        RotationCurve = RotationCurveLastFrame = 0.f;
        Pitch = 0;
    }else{
        Character->GetCharacterMovement()->bOrientRotationToMovement = false;
        Character->SetActorRotation(FRotator(0,0,0));
    }
}

void UCharacterAnimInstance::UpdateAnimationProperties(float deltaTime)
{
  if(!Character) return;

  DeltaTime = deltaTime;
  FVector v = Character->GetVelocity();
  v.Z = 0;
  Speed = v.Size();
  IsMoving = Speed != 0.f;

  /*switch (AttackState)
  {
  case ECharacterAttackState::Aiming:
      DEBUG_LOG_TICK("Aiming");
      break;
  case ECharacterAttackState::Drawback:
      DEBUG_LOG_TICK("Drawback");
      break;
  case ECharacterAttackState::Holding:
      DEBUG_LOG_TICK("Holding");
      break;
  case ECharacterAttackState::Release:
      DEBUG_LOG_TICK("Release");
      break;
  case ECharacterAttackState::NotAiming:
      DEBUG_LOG_TICK("Not Aiming");
      break;
  }*/

  if(OrientationType == EOrientationType::AimDirection){
      FRotator RootRotation = Character->GetAimRotator();
      RootRotation.Pitch = 0;
      RootRotation.Roll = 0;
      Character->SetActorRotation(RootRotation);

      USkeletalMeshSocket const* socket = Character->GetMesh()->GetSocketByName("spine_03Socket");

      AimRotation = Character->GetAimRotator();
      FRotator SocketRot = socket->GetSocketTransform(Character->GetMesh()).Rotator();

      MovementOffsetYaw = Character->GetAimRotationRelativeToMovement().Yaw;
      Pitch = AimRotation.Pitch;

      if(Speed > 0.f){
          LastMovementOffsetYaw  = MovementOffsetYaw;
      }

      turnInPlace();
  }


}

void UCharacterAnimInstance::checkMovement()
{
    //Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;

}

void UCharacterAnimInstance::turnInPlace()
{
    if(!Character) return;

    if(Speed == 0) {
        LastCharacterYaw = CurrentCharacterYaw;
        CurrentCharacterYaw = Character->GetActorRotation().Yaw;

        const float YawDelta{ CurrentCharacterYaw - LastCharacterYaw};

        //clamping [-180 , 180]
        RootYawOffset = UKismetMathLibrary::NormalizeAxis(RootYawOffset - YawDelta);

        // 1.0 if tuning , 0 if not
        const float tuning{GetCurveValue(TEXT("Turning"))};

        if(tuning > 0.f){
            RotationCurveLastFrame = RotationCurve;
            RotationCurve = GetCurveValue(TEXT("Rotation"));
            const float DeltaRotation{ RotationCurve - RotationCurveLastFrame };

            // turning left : right;
            RootYawOffset > 0 ? RootYawOffset -= DeltaRotation : RootYawOffset += DeltaRotation;

            const float ABSRootYawOffset { FMath::Abs(RootYawOffset)};
            if(ABSRootYawOffset > 90.f){
                const float YawExcess { ABSRootYawOffset - 90.F};
                RootYawOffset > 0 ? RootYawOffset -= YawExcess : RootYawOffset += YawExcess;
            }
        }

    }else{
        RootYawOffset = 0.f;
        CurrentCharacterYaw = Character->GetActorRotation().Yaw;
        LastCharacterYaw  = CurrentCharacterYaw;
        RotationCurveLastFrame = 0.f;
        RotationCurve = 0.f;
    }

}






















