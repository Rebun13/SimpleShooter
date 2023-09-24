// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* Pawn) {
    Super::PawnKilled(Pawn);
    
    APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController());
    if(PlayerController){
        PlayerController->GameHasEnded(nullptr, false);
    }
}