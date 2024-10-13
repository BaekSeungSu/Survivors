// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/WeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "Particles/ParticleSystemComponent.h"


AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = WeaponRoot;

	AttackEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Weapon Effect"));
	AttackEffect->SetupAttachment(WeaponRoot);

	AttackPower = 10.0f;
	Cooldown = 1.0f;
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaponBase::Attack()
{

}