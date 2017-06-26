// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector target,float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* Barrel);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UTankBarrel* Barrel = nullptr;

private: 
	void MoveBarrelTowards(FVector AimDirection);
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
