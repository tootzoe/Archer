// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SlowTimeManager.generated.h"


 class UActorComponent;

/**
 * 
 */
UCLASS()
class ARCHER_API USlowTimeManager : public UObject
{
	GENERATED_BODY()


      public:

      void AddFreeTicker(AActor* Ticker);
      void AddFreeTicker(UActorComponent *Ticker);
      void SetGlobalTimeDilation();
      void SetSlowModeTimeDilation();



    FORCEINLINE void SetWorldContext(AActor* a){WorldContext  = a;}


private:

     const float SLOW_TIME_DILATION = 0.1f;
    const float NORMAL_TIME_DILATION = 1.f;

    UPROPERTY()
    TArray<AActor*> TimeFreeActors;
    UPROPERTY()
    TArray<  UActorComponent*> TimeFreeActorComponents;
    UPROPERTY()
    AActor* WorldContext;


	
};
