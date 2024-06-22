// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TP_Char.h"

// Sets default values
ATP_Char::ATP_Char()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	playerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Player");
	playerMesh->SetupAttachment(GetCapsuleComponent());

	springArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	springArm->SetupAttachment(GetCapsuleComponent());

	cameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	cameraComp->SetupAttachment(springArm);

	bUseControllerRotationYaw = true;
	springArm->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ATP_Char::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATP_Char::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATP_Char::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed,
		this, &ATP_Char::JumpAction);
	PlayerInputComponent->BindAction("Jump", IE_Released,
		this, &ATP_Char::JumpEnd);

	PlayerInputComponent->BindAxis("MoveForward", this,
		&ATP_Char::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this,
		&ATP_Char::MoveRight);


	PlayerInputComponent->BindAxis("Turn", this,
		&ATP_Char::Turn);
	PlayerInputComponent->BindAxis("LookUp", this,
		&ATP_Char::LookUp);
}

void ATP_Char::JumpAction()
{
	Jump();
}

void ATP_Char::JumpEnd()
{
	StopJumping();
}

void ATP_Char::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ATP_Char::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void ATP_Char::Turn(float value)
{
	AddControllerYawInput(value);
}

void ATP_Char::LookUp(float value)
{
	if (invertAxis)
		AddControllerPitchInput(value);
	else
		AddControllerPitchInput(-value);
}

