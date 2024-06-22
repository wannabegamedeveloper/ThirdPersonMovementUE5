// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "DefGameModeBase.h"
#include "Enemy.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("Bullet");
	SetRootComponent(bulletMesh);
	
	projectileMovement = 
		CreateDefaultSubobject<UProjectileMovementComponent>("Projectile");
	projectileMovement->InitialSpeed = 200.f;
	projectileMovement->MaxSpeed = 200.f;

	OnActorHit.AddDynamic(this, &ABullet::OnCollision);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnCollision(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		if (ADefGameModeBase* gameMode = 
			Cast<ADefGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			gameMode->OnTargetHit();
			enemy->Destroy();
		}
	}

	Destroy();
}

