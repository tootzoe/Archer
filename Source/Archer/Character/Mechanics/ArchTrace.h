// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"


#include "ArchTrace.generated.h"


class AEnemy;

//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
UCLASS(Blueprintable)
class ARCHER_API UArchTrace : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArchTrace();

    void SetInterpolatedAimDirection(float DeltaTime);
    void SetBowSocket(USkeletalMeshComponent *SkeletalMeshComponent);
    void SetAimDirection(const AActor *ClosestTarget);
    void SetAimDirectionToTargetPosition(const FVector TargetLocation);
    void Shoot(TSubclassOf<class AProjectile> Projectile);
    void GetMouseLocationAndDirection(FVector &WorldLocation, FVector &WorldDirection);
    void FreeAimGamepad();
    void FreeAimMouse();

    AActor *GetMouseClosestTarget();
    AActor* GetGamepadClosestTarget();
    FVector2D GetActorScreenLocation(AActor* Target);

    FORCEINLINE bool IsThereAnyTarget() const { return AutoAimTargets.Num() > 0;}
    FORCEINLINE FRotator GetAimRotator() const { return AimDirection.Rotation();}
    FORCEINLINE void SetAutoAimTargets(TArray<AEnemy *> Targets)   { AutoAimTargets = Targets;}


    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FName BowSocketName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float AimInterpolationSpeed = 5.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float GamepadFreeAimSpeed = 10.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MaxAimAngle = 5.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool bAimOneMinimum  = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool bDebugAimLine  = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool bDebugActualAimLine  = true;



    USkeletalMeshComponent *SkeletalMeshComponent;



private:
    const float MIN_AIM_DISTANCE = 200.f;

    AActor *Owner;
    FCollisionObjectQueryParams CollisionObjectQueryParams;
    FCollisionQueryParams CollisionQueryParams;
    FVector AimDirection;
    FVector TargetAimDirection;
    float TargetAimDistance;
    class USkeletalMeshSocket const* BowSocket;
    TArray<AEnemy *> AutoAimTargets;
     class AArcherPlayerController* PlayerController;
     FVector2D FreeAimGamepadCursor;

     FHitResult LineTraceFromStartToEnd(FVector start, FVector end) const;
     void InitializeCollisionTypes();
     FVector GetSocketPosition() const;
     FVector2D GetPlayerScreenPosition() const;
     void GetPlayerStickPositionAndDirection(float &PlayerScreenLocation, FVector2D &PlayerDirection);
     TArray<AActor*> GetClosestTargetInPlayerDirection(FVector2D PlayerScreenLocation, FVector2D PlayerDirection);
    void FreeAim(const FHitResult &Hit);


		
};




















