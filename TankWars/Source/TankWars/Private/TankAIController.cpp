// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankWars.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller controlling %s"), *(ControlledTank->GetName()));
	}

}

void ATankAIController::Tick(float ticktime)
{
	Super::Tick(ticktime);

	if (GetPlayerTank())
	{
		AimTowardsPlayer();
	}
}

void ATankAIController::AimTowardsPlayer()
{
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}
