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
	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation)) {
		GetControlledTank()->AimAt(hitLocation);
	}
	

}
bool ATankPlayerController::GetSightRayHitLocation(FVector &hitLocation) const{
	
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX,viewportSizeY);
	auto screenLocation= FVector2D(viewportSizeX*CrossHairXLocation, 
								   viewportSizeY*CrossHairYLocation);
	FVector lookDirection;
	if (GetLookDirection(screenLocation, lookDirection)) {
		GetLookVectorHitLocation(hitLocation,lookDirection);
	}
	return true;
}
bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const{
	FVector location;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, location, lookDirection);
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector &hitLocation,FVector& lookDirection) const {
	FHitResult hitResult;
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(hitResult,startLocation,endLocation,
											 ECollisionChannel::ECC_Visibility)) {
		hitLocation = hitResult.Location;
		return true;
	}
	hitLocation = FVector(0);
	return false;

}



