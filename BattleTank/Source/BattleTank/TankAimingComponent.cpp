// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector target, float LaunchSpeed)
{
	if (!Barrel)
	{
		return;
	}
	FVector FireVelocity;
	if (!UGameplayStatics::SuggestProjectileVelocity(
		GetWorld(),
		FireVelocity,
		Barrel->GetSocketLocation("Projectile"),
		target,
		LaunchSpeed)
	) {
		return;
	}
	FVector AimDirection = FireVelocity.GetSafeNormal();
	auto OurTankName = GetOwner()->GetName();
	if (Barrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Barrel At: %s and Aiming At: %s Desired Direction: %s"), *OurTankName, *Barrel->GetComponentLocation().ToString(), *target.ToString(), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirection.Rotation();
	auto DeltaRotation = BarrelRotator - AimRotator;
	Barrel->ElevateDegreePerSeconds(5);

}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

