// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Bullet.h"
#include "GameFramework/SpringArmComponent.h"

#include "MainMover.generated.h"

UCLASS()
class UNREALTEST_API AMainMover : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* cubeMesh;

	UPROPERTY(EditAnywhere)
	UCameraComponent* cameraComp;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* springArm;

	UPROPERTY(EditAnywhere)
	bool invertAxis = false;

	UPROPERTY(EditAnywhere)
	float jumpForce = 200.f;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<ABullet> bulletClass;

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
};
