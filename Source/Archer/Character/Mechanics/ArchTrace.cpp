// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/SkeletalMeshSocket.h"


#include "../../Enemies/Enemy.h"
#include "../../Weapons/Projectile.h"
#include "../../Player/ArcherPlayerController.h"

#include "../../Utilities/Debug.h"

#include "ArchTrace.h"

// Sets default values for this component's properties
UArchTrace::UArchTrace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

    PrimaryComponentTick.TickInterval = 0.01f;
    PrimaryComponentTick.bCanEverTick = true;
    bAutoActivate = true;
    SetComponentTickEnabled(true);

    // ...
}

void UArchTrace::SetInterpolatedAimDirection(float DeltaTime)
{
    AimDirection = UKismetMathLibrary::VInterpTo(AimDirection , TargetAimDirection , DeltaTime , AimInterpolationSpeed);

    FVector StartPosition = GetSocketPosition();
    if(bDebugActualAimLine){
        DrawDebugLine(GetWorld(),
                      StartPosition,
                      StartPosition + AimDirection * TargetAimDistance,
                      FColor::Green,
                      false,
                      0.01f,
                      0.f,
                      10.f );
    }

}

void UArchTrace::SetBowSocket(USkeletalMeshComponent *skeletalMeshComponent)
{

    SkeletalMeshComponent = skeletalMeshComponent;
    if(SkeletalMeshComponent){
        BowSocket = SkeletalMeshComponent->GetSocketByName(BowSocketName);
    }
}

void UArchTrace::SetAimDirection(const AActor *ClosestTarget)
{
    SetAimDirectionToTargetPosition(ClosestTarget->GetActorLocation());
}

void UArchTrace::SetAimDirectionToTargetPosition(const FVector TargetLocation)
{
    FVector StartPostion = GetSocketPosition();
    TargetAimDirection = TargetLocation - StartPostion;
    TargetAimDistance = TargetAimDirection.Size();
    TargetAimDirection.Normalize();

    if(bDebugAimLine)
        DrawDebugLine(GetWorld(), StartPostion, TargetLocation, FColor::Red , false, 0.01f , 0.f ,10.f);
}

void UArchTrace::Shoot(TSubclassOf<AProjectile> ProjectileTemplate)
{
    FRotator ProjectileRotation = TargetAimDirection.Rotation();
    FVector ProjectileLocation = GetSocketPosition() + TargetAimDirection * 10.f;

    UWorld *World = GetWorld();
    if(!World) return;

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = Owner;
    SpawnParams.Instigator = Owner->GetInstigator();

    AProjectile *Projectile = World->SpawnActor<AProjectile>(ProjectileTemplate,
                                                             ProjectileLocation,
                                                             ProjectileRotation,
                                                             SpawnParams    );

    if(Projectile){
        Projectile->FireInDirection(TargetAimDirection);
    }


}

void UArchTrace::GetMouseLocationAndDirection(FVector &WorldLocation, FVector &WorldDirection)
{
    PlayerController->DeprojectMousePositionToWorld(WorldLocation,WorldDirection);

}

void UArchTrace::FreeAimGamepad()
{
    float StickX;
    float StickY;
    PlayerController->GetInputAnalogStickState(EControllerAnalogStick::CAS_RightStick , StickX, StickY);
    FVector2D StickPosition = FVector2D(StickX, StickY);

    FreeAimGamepadCursor += StickPosition * GamepadFreeAimSpeed;
    FVector Location;
    FVector Direction;
    PlayerController->DeprojectScreenPositionToWorld(FreeAimGamepadCursor.X , FreeAimGamepadCursor.Y ,Location, Direction);
    Direction.Normalize();
    Location += Direction * 10.f;
    DrawDebugPoint(GetWorld() , Location , 20.f , FColor::Red);

    FHitResult HitResult;
    PlayerController->GetHitResultAtScreenPosition(FreeAimGamepadCursor, ECC_PhysicsBody ,CollisionQueryParams, HitResult);
    FreeAim(HitResult);


}

void UArchTrace::FreeAimMouse()
{
    FHitResult MouseHitResult;
    PlayerController->GetHitResultUnderCursor(ECC_PhysicsBody, false, MouseHitResult);

    FreeAim(MouseHitResult);
}

AActor *UArchTrace::GetMouseClosestTarget()
{
    float MouseX;
    float MouseY;

    PlayerController->GetMousePosition(MouseX, MouseY);
    FVector2D MousePosition = FVector2D(MouseX, MouseY);

    FVector2D PlayerScreenLocation = GetPlayerScreenPosition();
    FVector2D PlayerDirection = MousePosition - PlayerScreenLocation;
    PlayerDirection.Normalize();

    TArray<AActor* > ClosestTargets = GetClosestTargetInPlayerDirection(PlayerScreenLocation, PlayerDirection);

    float ShortestDistance = TNumericLimits<float>::Max();
    AActor *ClosestTarget = nullptr;
    for( AActor *t : ClosestTargets){
        FVector2D TargetScreenLocation = GetActorScreenLocation(t);

        float Distance = (MousePosition - TargetScreenLocation).Size();
        if(Distance < ShortestDistance ){
            ShortestDistance = Distance;
            ClosestTarget = t;
        }
    }

    return ClosestTarget;
}

AActor *UArchTrace::GetGamepadClosestTarget()
{
    FVector2D PlayerScreenLocation = GetPlayerScreenPosition();

    float StickX;
    float StickY;
    PlayerController->GetInputAnalogStickState(EControllerAnalogStick::CAS_RightStick , StickX, StickY);
    FVector2D StickPosition = FVector2D(StickX, StickY);

    AActor *ClosestTarget = nullptr;

    float ShortestDistance = TNumericLimits<float>::Max();

    if(bAimOneMinimum && StickPosition == FVector2D(0)){

        for(AEnemy *e : AutoAimTargets){
            if(!e->IsAlive()) continue;

            FVector2D TargetScreenLocation = GetActorScreenLocation(e);
            float Distance = (PlayerScreenLocation - TargetScreenLocation).Size();

            if(Distance < ShortestDistance){
                ShortestDistance = Distance;
                ClosestTarget = e;
            }
        }

        return ClosestTarget;
    }

    FVector2D PlayerDirection = StickPosition;

    TArray<AActor *> ClosestTargets = GetClosestTargetInPlayerDirection(PlayerScreenLocation, PlayerDirection);
    TArray<float> TargetDistances;
    float MaxDistance = 0;

    for (AActor *t : ClosestTargets){
        FVector2D TargetScreenLocation = GetActorScreenLocation(t);
        float Distance  = (PlayerScreenLocation - TargetScreenLocation).Size();
        TargetDistances.Add(Distance);
        if(Distance > MaxDistance){
            MaxDistance = Distance;
        }
    }

    float ShortestRelativeDistance = TNumericLimits<float>::Max();
    float StickWeight = StickPosition.Size();

    for(int i = 0 ; i < ClosestTargets.Num() ; i ++) {
        float RelativeDistance = UKismetMathLibrary::Abs(StickWeight - (TargetDistances[i] / MaxDistance));
        if( RelativeDistance < ShortestRelativeDistance) {
            ShortestRelativeDistance = RelativeDistance;
            ClosestTarget = ClosestTargets[i];
        }
    }



    return ClosestTarget;
}

FVector2D UArchTrace::GetActorScreenLocation(AActor *Target)
{
    FVector2D TargetScreenLocation;
    PlayerController->ProjectWorldLocationToScreen(Target->GetActorLocation(), TargetScreenLocation, true);


    return TargetScreenLocation;
}


// Called when the game starts
void UArchTrace::BeginPlay()
{
	Super::BeginPlay();
    Owner = GetOwner();
    InitializeCollisionTypes();

    PlayerController = static_cast<AArcherPlayerController*>(UGameplayStatics::GetPlayerController(this, 0));

   // SetBowSocket();
    FreeAimGamepadCursor = FVector2D(1100, 600);

}

FHitResult UArchTrace::LineTraceFromStartToEnd(FVector start, FVector end) const
{
    FHitResult hitRsl;
    GetWorld()->LineTraceSingleByObjectType(hitRsl ,start , end , CollisionObjectQueryParams, CollisionQueryParams );
    return hitRsl;
}

void UArchTrace::InitializeCollisionTypes()
{
    TArray< TEnumAsByte<EObjectTypeQuery> > CollisionTypes;
    CollisionTypes.Emplace(ECollisionChannel::ECC_PhysicsBody);
    CollisionTypes.Emplace(ECollisionChannel::ECC_WorldStatic);
    CollisionTypes.Emplace(ECollisionChannel::ECC_WorldDynamic);
    CollisionTypes.Emplace(ECollisionChannel::ECC_Pawn);

    CollisionObjectQueryParams = FCollisionObjectQueryParams(CollisionTypes);
    CollisionQueryParams = FCollisionQueryParams();
    CollisionQueryParams.AddIgnoredActor(Owner);
}

FVector UArchTrace::GetSocketPosition() const
{
    return   BowSocket ? BowSocket->GetSocketLocation( SkeletalMeshComponent ) :
                        GetOwner()->GetActorLocation() + TargetAimDirection * 50.f;
}

FVector2D UArchTrace::GetPlayerScreenPosition() const
{
    FVector2D PlayerScreenLocation;
    FVector StartPosition = GetSocketPosition();
    PlayerController->ProjectWorldLocationToScreen(StartPosition, PlayerScreenLocation, true );


    return PlayerScreenLocation;
}

TArray<AActor *> UArchTrace::GetClosestTargetInPlayerDirection(FVector2D PlayerScreenLocation, FVector2D PlayerDirection)
{
    PlayerDirection.Normalize();

    TArray<AActor *> ClosestTargets;
    AActor *ClosestTarget = nullptr;

    float SmallestAngle = TNumericLimits<float>::Max();
    for( AEnemy *e : AutoAimTargets){
        if(!e->IsAlive()) continue;

        FVector2D TargetScreenLocation = GetActorScreenLocation(e);
        FVector2D Direction = TargetScreenLocation - PlayerScreenLocation;
        Direction.Normalize();

        float AimAtAngle = FMath::RadiansToDegrees(acosf(FVector2D::DotProduct(PlayerDirection, Direction)));

        if(AimAtAngle < MaxAimAngle){
            ClosestTargets.Add(e);
        }
        if(AimAtAngle < SmallestAngle) {
            SmallestAngle = AimAtAngle;
            ClosestTarget = e;
        }
    }

    if( bAimOneMinimum && ClosestTargets.Num() == 0 && ClosestTarget)
        ClosestTargets.Add(ClosestTarget);



    return ClosestTargets;
}

void UArchTrace::FreeAim(const FHitResult &Hit)
{
    if(!Hit.IsValidBlockingHit()) return;

    FVector HitLocation = Hit.Location;
    FVector StartPosition = GetSocketPosition();
    float Distance = UKismetMathLibrary::Vector_Distance(HitLocation , StartPosition);

    if(Distance < MIN_AIM_DISTANCE) return;

    TargetAimDirection = HitLocation - StartPosition;
    TargetAimDistance = TargetAimDirection.Size();
    TargetAimDirection.Normalize();
    FVector End = HitLocation + TargetAimDirection * 100;
    FHitResult HitResult = LineTraceFromStartToEnd(StartPosition, End);
    if(!HitResult.IsValidBlockingHit()) return;

    FVector HitResultLocation = HitResult.Location;
    TargetAimDirection = HitResultLocation - StartPosition;
    TargetAimDistance = TargetAimDirection.Size();
    TargetAimDirection.Normalize();

    if(bDebugAimLine){
        DrawDebugLine(GetWorld(), StartPosition, HitResultLocation, FColor::Red , false, 0.01f, 0.f , 10.f);
    }

}


// Called every frame
void UArchTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

