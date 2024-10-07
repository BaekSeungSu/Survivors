// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwordEffect.generated.h"

UCLASS()
class SURVIVORS_API ASwordEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	ASwordEffect();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Properties")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Properties")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Properties")
	float TravelDistance;


protected:
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	float DistanceTravelled;
	void MoveEffect(float DeltaTime);

};

