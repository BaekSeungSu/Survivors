

#include "Weapons/SwordProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

ASwordProjectile::ASwordProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Component"));
	CollisionComponent->InitSphereRadius(15.f);
	CollisionComponent->SetCollisionProfileName(TEXT("Projectile"));
	RootComponent = CollisionComponent;

	CollisionComponent->OnComponentHit.AddDynamic(this, &ASwordProjectile::OnHit);

	SwordProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Sword Projectile Movement Component"));
	SwordProjectileMovementComponent->MaxSpeed = 1000.f;
	SwordProjectileMovementComponent->InitialSpeed = 1000.f;
}

void ASwordProjectile::BeginPlay()
{
	Super::BeginPlay();
	SpanwParticle();
	StartLocation = GetActorLocation();
}

void ASwordProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DestroyProjectile();
}

void ASwordProjectile::SpanwParticle()
{
	if (ProjectileEffect)
	{
		UGameplayStatics::SpawnEmitterAttached(ProjectileEffect, RootComponent);
	}

}

void ASwordProjectile::DestroyProjectile()
{
	float DistanceTravelled = FVector::Dist(StartLocation, GetActorLocation());

	if(DistanceTravelled >= MaxRange)
	{
		Destroy();
	}
}


void ASwordProjectile::InitializeProjectile(FVector Direction, float Range, float Damage)
{
	MoveDirection = Direction.GetSafeNormal();
	MaxRange = Range;
	ProjectileDamage = Damage;

	SwordProjectileMovementComponent->Velocity = MoveDirection * SwordProjectileMovementComponent->InitialSpeed;
}

void ASwordProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
}