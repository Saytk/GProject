#include "ProjectileLauncherComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"
#include <GameFramework/ProjectileMovementComponent.h>
UProjectileLauncherComponent::UProjectileLauncherComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true); // Ensure the component is replicated
}

void UProjectileLauncherComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UProjectileLauncherComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UProjectileLauncherComponent::LaunchProjectile()
{
	if (GetOwner()->HasAuthority())
	{
		SpawnProjectile();
	}
	else
	{
		ServerLaunchProjectile();
	}
}

void UProjectileLauncherComponent::ServerLaunchProjectile_Implementation()
{
	SpawnProjectile();
}

bool UProjectileLauncherComponent::ServerLaunchProjectile_Validate()
{
	return true;
}


void UProjectileLauncherComponent::SpawnProjectile()
{
	if (!ProjectileClass) return;

	
	UE_LOG(LogTemp, Warning, TEXT("Projectile Launched"));
	FVector SpawnLocation = GetOwner()->GetActorLocation();
	FRotator SpawnRotation = GetOwner()->GetActorRotation();

	AActor* Projectile = GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation);
	int a = 39;

	if (Projectile)
	{
		// Initialize the projectile if needed
	}
}

