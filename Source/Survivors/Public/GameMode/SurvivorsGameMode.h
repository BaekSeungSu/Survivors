// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SurvivorsGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVORS_API ASurvivorsGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void ActorDied(ACharacter* DeadCharacter);

protected:
	virtual void BeginPlay() override;

private:
	class ASurvivorsCharacter* SurvivorsCharacter;
	class AEnemy* Enemy;
};




