// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveElement.generated.h"

UCLASS(Blueprintable)
class ARCHER_API AInteractiveElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveElement();
    virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
    UStaticMeshComponent *MeshComponent;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly)
    class UBoxComponent *BoxComponent;



    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
                   FVector NormalImpulse, const FHitResult& Hit);

};
