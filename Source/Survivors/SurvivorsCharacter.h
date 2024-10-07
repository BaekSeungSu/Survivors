// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SurvivorsCharacter.generated.h"

UCLASS()
class SURVIVORS_API ASurvivorsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASurvivorsCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	class AWeaponBase* CurrentWeapon;

private:
	float MoveForwardValue;
	float MoveRightValue;
	
	FTimerHandle AttackTimerHandle;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float deltatime);
	void Attack();
};
