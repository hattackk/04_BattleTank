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
	
public:
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


	

private:
	/*************************************************/
	/** GetSightRayHitLocation();                   **/
	/*************************************************/
	/* Find what the line trace hits                 */
	/*************************************************/

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	
	
};
