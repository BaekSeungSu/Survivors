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

	void InitializeProjectile(FVector Direction, float Range, float Damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	class UParticleSystem* ProjectileEffect;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	class UProjectileMovementComponent* SwordProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	class USphereComponent* CollisionComponent;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SpanwParticle();
	void DestroyProjectile();

	FVector MoveDirection;
	FVector StartLocation;

	float MaxRange;
	float ProjectileDamage;

};





