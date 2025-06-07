// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveElement.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
AInteractiveElement::AInteractiveElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box");
    BoxComponent->InitBoxExtent(FVector(30.f, 30.f , 30.f));
    RootComponent = BoxComponent;
    //BoxComponent->SetCollisionProfileName("");

    BoxComponent->CanCharacterStepUpOn  = ECB_No;
    BoxComponent->SetShouldUpdatePhysicsVolume(false);
    BoxComponent->SetCanEverAffectNavigation(false);
    BoxComponent->bDynamicObstacle = false;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    MeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AInteractiveElement::BeginPlay()
{
	Super::BeginPlay();

}

void AInteractiveElement::OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor,
                                UPrimitiveComponent *OtherComponent, FVector NormalImpulse, const FHitResult &Hit)
{

}

// Called every frame
void AInteractiveElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

