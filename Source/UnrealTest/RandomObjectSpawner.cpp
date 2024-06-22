
// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomObjectSpawner.h"

// Sets default values for this component's properties
URandomObjectSpawner::URandomObjectSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URandomObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void URandomObjectSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AMainMover* playerClass = Cast<AMainMover>(playerActor);
	if (playerClass == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("TEST"));

	if (playerClass)
		playerClass->cubeMesh->
		SetWorldLocation(FVector(0.f, 0.f, 0.f));
}

