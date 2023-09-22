// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay() {
    Super::BeginPlay();
    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AShooterAIController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    if(PlayerPawn && LineOfSightTo(PlayerPawn)) {
        SetFocus(PlayerPawn);
        MoveToActor(PlayerPawn, AcceptanceRadius);
    } else {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }
}
