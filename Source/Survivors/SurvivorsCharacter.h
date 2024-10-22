// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Weapons/WeaponBase.h"
#include "SurvivorsCharacter.generated.h"


UCLASS()
class SURVIVORS_API ASurvivorsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASurvivorsCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();

	void HandleDestruction();

	APlayerController* GetPlayerController() const {return PlayerController;}

protected:
	virtual void BeginPlay() override;

private:
	float MoveForwardValue;
	float MoveRightValue;
	
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float deltatime);
	void EquipWeapons();

	UPROPERTY(VisibleAnywhere)
	class UAttributeComponent* Attributes;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AWeaponBase> WeaponBaseClass;

    UPROPERTY()
    AWeaponBase* EquippedWeapon;

	APlayerController* PlayerController;

};
