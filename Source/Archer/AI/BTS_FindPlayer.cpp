// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_FindPlayer.h"

#include "../Character/ArcherCharacter.h"
#include "EnemyAIController.h"


#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"



UBTS_FindPlayer::UBTS_FindPlayer()
{

}

void UBTS_FindPlayer::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory , DeltaSeconds);


    ACharacter *ArcherCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

    AEnemyAIController *AIController = static_cast<AEnemyAIController*>(OwnerComp.GetAIOwner());
    if(AIController)
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(AIController->GetPlayerKey() , ArcherCharacter);
    }

}


















