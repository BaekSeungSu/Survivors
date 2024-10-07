// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Sword.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Weapons/SwordEffect.h"

ASword::ASword()
{
	AttackRange = 300.0f;
    AttackSpeed = 1.0f;
}

void ASword::Attack()
{
	AActor* OwnerActor = GetOwner();
    if(!OwnerActor) return;

    FVector AttackLocation = OwnerActor->GetActorLocation() + (OwnerActor->GetActorForwardVector()* 50.0f);
    FRotator AttacRotation = OwnerActor->GetActorRotation();

    SpawnSwordSlashEffect();

    FVector EndLocation = AttackLocation + (OwnerActor->GetActorForwardVector() * AttackRange);

    TArray<FHitResult> HitResults;
    FCollisionShape CollisionShape = FCollisionShape::MakeSphere(50.0f);

    if(GetWorld()->SweepMultiByChannel(HitResults, AttackLocation, EndLocation, FQuat::Identity, ECC_GameTraceChannel1, CollisionShape))
    {
        for(const FHitResult& Hit : HitResults)
        {
            AActor* HitActor = Hit.GetActor();
            if(HitActor)
            {
                UGameplayStatics::ApplyDamage(HitActor, AttackPower, nullptr, this, nullptr);
            }
        }
    }
}

void ASword::SpawnSwordSlashEffect()
{
	AActor* OwnerActor = GetOwner();
    if (!OwnerActor) return;

    // 이펙트 생성 위치 및 회전 설정
    FVector EffectLocation = OwnerActor->GetActorLocation() + (OwnerActor->GetActorForwardVector() * 50.0f);
    FRotator EffectRotation = OwnerActor->GetActorRotation();

    // 이펙트를 스폰
    if (AttackEffectClass)
    {
        ASwordEffect* Effect = GetWorld()->SpawnActor<ASwordEffect>(AttackEffectClass, EffectLocation, EffectRotation);
        if (Effect)
        {
            Effect->Direction = EffectRotation.Vector(); // 이펙트 이동 방향 설정
            Effect->Speed = 1000.0f; // 이펙트 이동 속도 설정
            Effect->TravelDistance = AttackRange; // 이펙트 이동 거리 설정
        }
    }
}
