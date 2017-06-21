// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	ATankPlayerController();
	void AimTowardsCrosshair();

public:

	bool GetSightHitLocation(FVector& hitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;
	void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000;

};
