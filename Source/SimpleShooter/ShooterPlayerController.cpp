// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) {
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    UUserWidget* GameOverScreen;
    if(bIsWinner) {
        GameOverScreen = CreateWidget(this, WinScreenClass);
    } else {
        GameOverScreen = CreateWidget(this, LoseScreenClass);
    }
    
    if(GameOverScreen) {
        GameOverScreen->AddToViewport();
    }
    
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}