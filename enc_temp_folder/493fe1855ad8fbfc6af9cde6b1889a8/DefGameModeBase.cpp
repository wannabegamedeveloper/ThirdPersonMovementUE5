// Fill out your copyright notice in the Description page of Project Settings.


#include "DefGameModeBase.h"
#include "DefGameState.h"

ADefGameModeBase::ADefGameModeBase()
{
	pointsToWin = 5;
}

void ADefGameModeBase::OnTargetHit()
{
	if (ADefGameState* gameState = Cast<ADefGameState>(GameState))
	{
		gameState->currentPoints++;

		if (gameState->currentPoints >= pointsToWin)
		{
			UE_LOG(LogTemp, Warning, TEXT("YOU WON!!"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("YOU SCORED %d points."), 
				gameState->currentPoints);
		}
	}
}