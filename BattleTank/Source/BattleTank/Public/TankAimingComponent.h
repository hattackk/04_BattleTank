// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "kismet/GamePlayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTankAimingComponent();
	


	void SetBarrelReference(UStaticMeshComponent *barrelToSet);

	// Called when the game starts
	virtual void BeginPlay() override;


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector hitLocation,float launchSpeed);
private:
	
	UStaticMeshComponent * Barrel = nullptr;
	void MoveBarrelTowards(FVector);
	


	
};
