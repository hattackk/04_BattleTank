// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	ATank * tank = GetControlledTank();
	if (tank) {
		UE_LOG(LogTemp, Warning, TEXT("Got player controller %s"), *(tank->GetName()));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Didn't get ATank"));
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}


