// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class UNREALTEST_API AEnemy : public AActor
{
	GENERATED_BODY()
	
private:
	UMaterialInstanceDynamic* dynamicMat;

public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* enemyMesh;

	UPROPERTY(EditAnywhere, Category = "Materials")
	UMaterialInterface* mat;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeColor(FVector color);
};
