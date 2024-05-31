// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"



#include "../../Enemies/Enemy.h"
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

}

void UArchTrace::SetAimDirectionToTargetPosition(const FVector TargetLocation)
{

}

void UArchTrace::Shoot(TSubclassOf<AProjectile> Projectile)
{

}

void UArchTrace::GetMouseLocationAndDirection(FVector &WorldLocation, FVector &WorldDirection)
{
    PlayerController->DeprojectMousePositionToWorld(WorldLocation,WorldDirection);

}

void UArchTrace::FreeAimGamepad()
{

}

void UArchTrace::FreeAimMouse()
{

}

AActor *UArchTrace::GetMouseClosestTarget()
{

}

AActor *UArchTrace::GetGamepadClosestTarget()
{

}

FVector2D UArchTrace::GetActorScreenLocation(AActor *Target)
{

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
    return BowSocket ? BowSocket->GetSocketLocation(SkeletalMeshComponent) :
                       GetOwner()->GetActorLocation() + TargetAimDirection * 50.f;
}

FVector2D UArchTrace::GetPlayerScreenPosition() const
{

}

TArray<AActor *> UArchTrace::GetClosestTargetInPlayerDirection(FVector2D PlayerScreenLocation, FVector2D PlayerDirection)
{

}

void UArchTrace::FreeAim(const FHitResult &Hit)
{

}


// Called every frame
void UArchTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

