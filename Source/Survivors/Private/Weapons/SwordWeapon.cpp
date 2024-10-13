// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/SwordWeapon.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Particles/ParticleSystemComponent.h"

ASwordWeapon::ASwordWeapon()
{
    PrimaryActorTick.bCanEverTick = true;

    AttackRange = 500.f;
    EffectSpeed = 100.f;
    CanAttack = true;
}

void ASwordWeapon::BeginPlay()
{
	Super::BeginPlay();
	

}

void ASwordWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(AttackEffect->IsActive())
    {
        MoveEffect(DeltaTime);
    }
}

void ASwordWeapon::Attack()
{
    if(CanAttack)
    {
        CanAttack = false;

        StartLocation = GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * 100.f;
        EndLocation = StartLocation + GetOwner()->GetActorForwardVector() * AttackRange;

        AttackEffect->SetWorldLocation(StartLocation);
        AttackEffect->Activate();

        GetWorldTimerManager().SetTimer(CooldownTimerHandle, this, &ASwordWeapon::OnAttackCooldown, Cooldown, false);
    }
}

void ASwordWeapon::MoveEffect(float DeltaTime)
{
    FVector CurrentLocation = AttackEffect->GetComponentLocation();
    FVector Direction = (EndLocation - StartLocation).GetSafeNormal();
    FVector NewLocation = CurrentLocation + Direction * EffectSpeed * DeltaTime;

    if(FVector::Dist(NewLocation, StartLocation) >= AttackRange)
    {
        AttackEffect->Deactivate();
    }
    else
    {
        AttackEffect->SetWorldLocation(NewLocation);
    }
}

void ASwordWeapon::OnAttackCooldown()
{
    CanAttack = true;
}