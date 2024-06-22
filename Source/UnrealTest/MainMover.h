// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Bullet.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

#include "MainMover.generated.h"

UCLASS()
class UNREALTEST_API AMainMover : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* cubeMesh;

private:
	UPROPERTY(EditAnywhere)
	UCameraComponent* cameraComp;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* springArm;

	UPROPERTY(EditAnywhere)
	bool invertAxis = false;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<ABullet> bulletClass;

	UPROPERTY(EditAnywhere, Category = "Jumping")
		float jumpForce = 200.f;

	UFloatingPawnMovement* pawn;


public:
	// Sets default values for this pawn's properties
	AMainMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);

	void Turn(float value);
	void LookUp(float value);

	void Jump();

	void Shoot();

	UFUNCTION()
	void OnCollision(AActor* SelfActor, 
		AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
