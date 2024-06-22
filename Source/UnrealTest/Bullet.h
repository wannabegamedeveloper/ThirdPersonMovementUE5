// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Bullet.generated.h"

UCLASS()
class UNREALTEST_API ABullet : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* bulletMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UProjectileMovementComponent* projectileMovement;

public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnCollision(AActor* SelfActor, AActor* OtherActor, 
		FVector NormalImpulse, const FHitResult& Hit);
};
