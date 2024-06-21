// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMover.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMainMover::AMainMover()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	cubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	SetRootComponent(cubeMesh);

	springArm = CreateDefaultSubobject<USpringArmComponent>("CameraArm");
	springArm->TargetArmLength = 500.f;
	springArm->SetupAttachment(cubeMesh);

	cameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	cameraComp->SetupAttachment(springArm);

	bUseControllerRotationYaw = true;
	springArm->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AMainMover::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AMainMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainMover::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, 
		&AMainMover::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this,
		&AMainMover::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMainMover::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AMainMover::LookUp);
}

void AMainMover::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
	
}

void AMainMover::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AMainMover::Turn(float value)
{
	AddControllerYawInput(value);
}

void AMainMover::LookUp(float value)
{
	if (invertAxis)
		AddControllerPitchInput(value);
	else
		AddControllerPitchInput(-value);
}

