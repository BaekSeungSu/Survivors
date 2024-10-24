// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/SurvivorsGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "../SurvivorsCharacter.h"
#include "Enemy/Enemy.h"

void ASurvivorsGameMode::BeginPlay()
{
	Super::BeginPlay();

    SurvivorsCharacter = Cast<ASurvivorsCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void ASurvivorsGameMode::ActorDied(ACharacter* DeadCharacter)
{
	if(DeadCharacter == SurvivorsCharacter)
    {
        SurvivorsCharacter->HandleDestruction();
        if(SurvivorsCharacter->GetPlayerController())
        {
            SurvivorsCharacter->DisableInput(SurvivorsCharacter->GetPlayerController());
            SurvivorsCharacter->GetPlayerController()->bShowMouseCursor = false;
        }
        
    }
    else if(AEnemy* DiedEnemy = Cast<AEnemy>(DeadCharacter))
    {
        DiedEnemy->HandleDestruction();
    }
}