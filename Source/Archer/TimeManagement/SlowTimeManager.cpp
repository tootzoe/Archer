// Fill out your copyright notice in the Description page of Project Settings.



#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"



#include "SlowTimeManager.h"


void USlowTimeManager::AddFreeTicker(AActor *Ticker)
{
    TimeFreeActors.Add(Ticker);
}

void USlowTimeManager::AddFreeTicker(UActorComponent *Ticker)
{
    TimeFreeActorComponents.Add(Ticker);
}

void USlowTimeManager::SetGlobalTimeDilation()
{
    UGameplayStatics::SetGlobalTimeDilation(WorldContext->GetWorld() , NORMAL_TIME_DILATION);

    for(AActor *a : TimeFreeActors)
        {
            a->CustomTimeDilation = NORMAL_TIME_DILATION;
        }

        for(UActorComponent *ac : TimeFreeActorComponents){
           // ac->ti
        }

}

void USlowTimeManager::SetSlowModeTimeDilation()
{
    UGameplayStatics::SetGlobalTimeDilation(WorldContext->GetWorld() , SLOW_TIME_DILATION);

    for(AActor *a : TimeFreeActors)
        {
            a->CustomTimeDilation = SLOW_TIME_DILATION;
        }

        for(UActorComponent *ac : TimeFreeActorComponents){
           // ac->ti
        }

}















