// Fill out your copyright notice in the Description page of Project Settings.



#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"







#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    if(!CollisionComponent){
        CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
        CollisionComponent->InitSphereRadius( 15.f);
        RootComponent = CollisionComponent;
    }

    if(!ProjectileMovementComponent){
        ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PorjectileMovementComponent"));
        ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
        ProjectileMovementComponent->InitialSpeed = 3000.f;
        ProjectileMovementComponent->MaxSpeed = 3000.f;
        ProjectileMovementComponent->bRotationFollowsVelocity = true;
        ProjectileMovementComponent->bShouldBounce = true;
        ProjectileMovementComponent->Bounciness = 0.3f;
        ProjectileMovementComponent->ProjectileGravityScale = 0.f;

    }

    if (!Mesh) {
        Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
        Mesh->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
        Mesh->SetupAttachment(RootComponent);
    }

    InitialLifeSpan = 3.0f;

    CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
    CollisionComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

}

void AProjectile::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, FVector NormalImpulse, const FHitResult &Hit)
{




    if(Cast<AProjectile>(OtherActor)) return;

    Destroy();

}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::FireInDirection(const FVector &ShootDirection)
{
    ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

