// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/SwordWeapon.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Weapons/SwordProjectile.h"
#include "TimerManager.h"


ASwordWeapon::ASwordWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    AttackRange = 500.f;
    CanAttack = true;
}

void ASwordWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASwordWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASwordWeapon::Attack()
{
    if(CanAttack && ProjectileClass)
    {
        CanAttack = false;

        StartLocation = GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * 50.f;
        AttackDirection = GetOwner()->GetActorForwardVector();

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();
    
        ASwordProjectile* Projectile = GetWorld()->SpawnActor<ASwordProjectile>(ProjectileClass, StartLocation, FRotator::ZeroRotator, SpawnParams);
        if (Projectile)
        {
            Projectile->InitializeProjectile(AttackDirection, AttackRange, AttackPower);
        }

        GetWorldTimerManager().SetTimer(CooldownTimerHandle, this, &ASwordWeapon::OnAttackCooldown, Cooldown, false);
    }
}

void ASwordWeapon::OnAttackCooldown()
{
    CanAttack = true;
}