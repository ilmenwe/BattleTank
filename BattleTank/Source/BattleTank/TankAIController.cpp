// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* controlledTank = GetControlledTank();
	if (controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing %s"), *(controlledTank->GetName()));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No controlled tank found!"));
	}

	ATank* targetTank = GetPlayerTank();
	if (targetTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target Controller %s"), *(targetTank->GetName()));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Target Controller found!"));
	}
	
}

void ATankAIController::Tick(float DeltaTime)
{
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}	

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* result = nullptr;
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		result = Cast<ATank>(PlayerController->GetPawn());
	}
	return result;
}