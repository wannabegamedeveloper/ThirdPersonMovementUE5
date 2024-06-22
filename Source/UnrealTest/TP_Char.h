// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TP_Char.generated.h"

UCLASS()
class UNREALTEST_API ATP_Char : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* cameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* springArm;

	UPROPERTY(EditAnywhere, Category = "Player")
	class UStaticMeshComponent* playerMesh;

	UPROPERTY(EditAnywhere, Category = "Player");
	bool invertAxis;

public:
	// Sets default values for this character's properties
	ATP_Char();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void JumpAction();
	void JumpEnd();

	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);
};
