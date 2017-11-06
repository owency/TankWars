// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum Driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// This is max force (Per Track) in Neutons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDriveForce = 400000; // Assume tank is 40Tonne and 1G Accelleration
};
