// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChangedSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVORS_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);
	
	FOnHealthChangedSignature OnHealthChanged;

	bool IsAlive();

protected:
	virtual void BeginPlay() override;

private:
	// 현재 체력
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Health;

	// 최대 체력
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth;
	
	class ASurvivorsGameMode* SurvivorsGameMode; 
};

