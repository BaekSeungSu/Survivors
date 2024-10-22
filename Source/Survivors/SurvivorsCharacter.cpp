// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivorsCharacter.h"
#include "Public/Components/AttributeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"

ASurvivorsCharacter::ASurvivorsCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

    Attributes->CreateDefaultSubobject<UAttributeComponent>(TEXT("Attributes"));

    GetCharacterMovement()->bOrientRotationToMovement = true;
    bUseControllerRotationYaw = false;
}

void ASurvivorsCharacter::BeginPlay()
{
	Super::BeginPlay();
    PlayerController = Cast<APlayerController>(GetController());
    EquipWeapons();
	
}

void ASurvivorsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    Turn(DeltaTime);
    Attack();
}

void ASurvivorsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASurvivorsCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASurvivorsCharacter::MoveRight);

}

void ASurvivorsCharacter::Attack()
{
    if(EquippedWeapon)
    {
        EquippedWeapon->Attack();
    }
}

void ASurvivorsCharacter::HandleDestruction()
{
    SetActorHiddenInGame(true);
    SetActorTickEnabled(false);
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

void ASurvivorsCharacter::EquipWeapons()
{
    if(WeaponBaseClass)
    {
        FActorSpawnParameters Spanwparams;
        Spanwparams.Owner = this;
        Spanwparams.Instigator = GetInstigator();

        EquippedWeapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponBaseClass, Spanwparams);

        if(EquippedWeapon)
        {
            EquippedWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("WeaponSocket"));
        }

    }
}
