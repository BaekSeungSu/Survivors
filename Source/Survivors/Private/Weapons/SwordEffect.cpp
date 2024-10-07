// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/SwordEffect.h"

ASwordEffect::ASwordEffect()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Speed = 1000.0f;
	TravelDistance = 300.0f;
	DistanceTravelled = 0.0f;
}

// Called when the game starts or when spawned
void ASwordEffect::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void ASwordEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ASwordEffect::MoveEffect(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + (Direction * Speed * DeltaTime);
	SetActorLocation(NewLocation);

	DistanceTravelled += (Direction * Speed * DeltaTime).Size();

	if(DistanceTravelled >= TravelDistance)
	{
		Destroy();
	}
}


