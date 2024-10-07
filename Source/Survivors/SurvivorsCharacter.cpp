// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivorsCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapons/WeaponBase.h"

ASurvivorsCharacter::ASurvivorsCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    bUseControllerRotationYaw = false;
}

void ASurvivorsCharacter::BeginPlay()
{
	Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &ASurvivorsCharacter::Attack, 1.0f, true);
	
}

void ASurvivorsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Turn(DeltaTime);
}

void ASurvivorsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASurvivorsCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASurvivorsCharacter::MoveRight);

}

void ASurvivorsCharacter::MoveForward(float AxisValue)
{
	MoveForwardValue = AxisValue;
}

void ASurvivorsCharacter::MoveRight(float AxisValue)
{
	MoveRightValue = AxisValue;
}

void ASurvivorsCharacter::Turn(float deltatime)
{
    FVector InputDirection = FVector(MoveForwardValue, MoveRightValue, 0.0f);

    if(!InputDirection.IsNearlyZero())
    {
        FRotator TargetRotation = InputDirection.Rotation();
        TargetRotation.Pitch = 0.0f;
        TargetRotation.Roll = 0.0f;

        FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, deltatime, 10.0f);
        SetActorRotation(NewRotation);

        AddMovementInput(InputDirection.GetSafeNormal());
    }

}

void ASurvivorsCharacter::Attack()
{
    if(CurrentWeapon)
    {
        CurrentWeapon->Attack();
    }
}


