// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DefGameState.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTEST_API ADefGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ADefGameState();

	int currentPoints;
};
