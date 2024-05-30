// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"





#include "Projectile.generated.h"

UCLASS()
class ARCHER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




    UPROPERTY(VisibleDefaultsOnly)
    class USphereComponent* CollisionComponent;
    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovementComponent;
    UPROPERTY(VisibleDefaultsOnly)
    UStaticMeshComponent* Mesh;


    UFUNCTION()
    void OnHit(UPrimitiveComponent *HitComponent, AActor* OtherActor,
               UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit );


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;




    void FireInDirection(const FVector &ShootDirection);






};











