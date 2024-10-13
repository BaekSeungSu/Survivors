// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/SwordProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ASwordProjectile::ASwordProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASwordProjectile::BeginPlay()
{
	Super::BeginPlay();

	SpanwParticle();
	
}

// Called every frame
void ASwordProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveParticle(DeltaTime);
}

void ASwordProjectile::SpanwParticle()
{
	if (ProjectileEffect)
	{
		UGameplayStatics::SpawnEmitterAttached(ProjectileEffect, RootComponent);
	}

	StartLocation = GetActorLocation();
}

void ASwordProjectile::MoveParticle(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + (MoveDirection * ProjectileSpeed * DeltaTime);
	SetActorLocation(NewLocation);

	if(FVector::Dist(StartLocation, NewLocation) >= MaxRange)
	{
		Destroy();
	}

}

void ASwordProjectile::InitializeProjectile(FVector Direction, float Speed, float Range)
{
	MoveDirection = Direction.GetSafeNormal();
	ProjectileSpeed = Speed;
	MaxRange = Range;
}