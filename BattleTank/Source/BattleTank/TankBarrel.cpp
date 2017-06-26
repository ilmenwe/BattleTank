// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float DegreePerSeconds)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate called with value: %s"), *FString::FromFloat(DegreePerSeconds));
}