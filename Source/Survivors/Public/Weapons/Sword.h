// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponBase.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVORS_API ASword : public AWeaponBase
{
	GENERATED_BODY()

public:
	ASword();

	virtual void Attack() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	float AttackSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	TSubclassOf<AActor> AttackEffectClass;


protected:
	void SpawnSwordSlashEffect();
	
};







