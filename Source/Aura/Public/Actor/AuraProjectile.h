// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraProjectile.generated.h"


class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class AURA_API AAuraProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraProjectile();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherActorIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
private:
	TObjectPtr<USphereComponent> Sphere;
};
