// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	
private:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	/*************************************************/
	/** GetControlledTank();                        **/
	/*************************************************/
	/* Returns a pointer to the tank being           */
	/* controlled by the player                      */
	/*************************************************/

	ATank * GetControlledTank() const;

	/*************************************************/
	/** AimTowardsCrosshair();                      **/
	/*************************************************/
	/* Start the tank moving the barrel so that a    */
	/* shot would hit where the crosshairs are       */
	/* pointing.                                     */
	/*************************************************/

	void AimTowardsCrosshair();

	bool GetLookVectorHitLocation(FVector&,FVector&)const;
	bool GetLookDirection(FVector2D,FVector&) const;


	/*************************************************/
	/** GetSightRayHitLocation();                   **/
	/*************************************************/
	/* Find what the line trace hits                 */
	/*************************************************/

	bool GetSightRayHitLocation(FVector& HitLocation) const;


	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;

	FVector LineTraceEnd;

	FVector2D ScreenLocation;
	
};
