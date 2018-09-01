// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "BattleTank.h"


//Tick
//Super
// AimeTowardsCrosshair();
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	

}
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

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) {return;}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"),*HitLocation.ToString());

		//Get world location of linetrace through crosshair
		// if it hits the landscape
		//tell controlled tank to aim at this point

	}


}
bool ATankPlayerController::GetSightRayHitLocation(FVector &Hitlocation) const{
	//GetWorld()->GetFirstPlayerController()->
	Hitlocation = FVector(1.0);
	return true;


}


