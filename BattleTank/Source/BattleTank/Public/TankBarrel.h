// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Tank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Elevate(float degreesPerSecond);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
	float minElevation = 0;
	
	
	
	
};
