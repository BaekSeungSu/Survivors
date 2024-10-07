// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class SURVIVORS_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponBase();

	// 모든 무기는 기본적으로 공격력을 가짐
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	float AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UParticleSystem* AttackEffect;

	// 모든 무기는 공격 행위를 함
	virtual void Attack();

protected:
	virtual void BeginPlay() override;


};
