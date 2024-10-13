// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwordProjectile.generated.h"

UCLASS()
class SURVIVORS_API ASwordProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASwordProjectile();

	virtual void Tick(float DeltaTime) override;

	void InitializeProjectile(FVector Direction, float Speed, float Range);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UParticleSystem* ProjectileEffect;

protected:
	virtual void BeginPlay() override;

private:
	void SpanwParticle();
	void MoveParticle(float DeltaTime);

	FVector MoveDirection;
	FVector StartLocation;

	float ProjectileSpeed;
	float MaxRange;

};


