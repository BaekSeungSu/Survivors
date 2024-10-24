// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AttributeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameMode/SurvivorsGameMode.h"

UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UAttributeComponent::TakeDamage);

	SurvivorsGameMode = Cast<ASurvivorsGameMode>(UGameplayStatics::GetGameMode(this));
}

void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAttributeComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	if(Damage <= 0.f) return;

	Health -= Damage;
	OnHealthChanged.Broadcast();
	
	UE_LOG(LogTemp, Warning, TEXT("Health : %f"), Health);

	if(Health <= 0.0f && SurvivorsGameMode)
	{
		SurvivorsGameMode->ActorDied(Cast<ACharacter>(DamagedActor));
	}
	
}
