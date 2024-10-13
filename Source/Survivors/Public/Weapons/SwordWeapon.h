// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponBase.h"
#include "SwordWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVORS_API ASwordWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	ASwordWeapon();
	
	virtual void Tick(float DeltaTime) override;
	virtual void Attack() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    TSubclassOf<class ASwordProjectile> ProjectileClass;

protected:
	virtual void BeginPlay() override;

private:
	void OnAttackCooldown();
	void MoveEffect(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackRange;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float EffectSpeed;

	FTimerHandle CooldownTimerHandle;
	bool CanAttack;

	FVector AttackDirection;
	FVector StartLocation;
	FVector EndLocation;

};
