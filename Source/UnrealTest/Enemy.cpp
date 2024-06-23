// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	enemyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Enemy");
	SetRootComponent(enemyMesh);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::ChangeColor(FVector color)
{
	dynamicMat = UMaterialInstanceDynamic::Create(mat, this);
	dynamicMat->SetVectorParameterValue("Color", color);

	enemyMesh->SetMaterial(0, dynamicMat);
}

