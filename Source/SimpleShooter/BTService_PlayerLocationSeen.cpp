// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationSeen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTService_PlayerLocationSeen::UBTService_PlayerLocationSeen() {
    NodeName = TEXT("Update Player Location If Seen");
}

void UBTService_PlayerLocationSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if(!PlayerPawn) return;

    if(!OwnerComp.GetAIOwner()) return;

    if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
    } else {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
        
}