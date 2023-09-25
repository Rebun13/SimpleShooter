// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* Pawn) {
    Super::PawnKilled(Pawn);
    
    APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController());
    if(PlayerController){
        EndGame(false);
        return;
    }

    for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld())) {
        if(!Controller->IsDead()) {
            return;
        }
    }
    EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for(AController* Controller : TActorRange<AController>(GetWorld())) {
        Controller->GameHasEnded(Controller->GetPawn(), Controller->IsPlayerController() == bIsPlayerWinner);
    }

}
