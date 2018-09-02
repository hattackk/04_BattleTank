// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent *barrelToSet) {
	Barrel = barrelToSet;
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector hitLocation,float launchSpeed) {
	if (!Barrel) { return; }
	FVector outLaunchVelocity;
	FVector startLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calc the outlaunchvelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this,outLaunchVelocity,startLocation,hitLocation,launchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace)) {
		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimDirection);
	}
}
void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection) {
	auto barrelRotator = Barrel->GetForwardVector().Rotation();
	auto aimAsRotator = aimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("Aim as rotator: %s"), *aimAsRotator.ToString());




}