// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

/**
 * @brief Projectile actor that applies gameplay effects on hit.
 */
UCLASS()
class AURA_API AAuraProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	/** @brief Default constructor */
	AAuraProjectile();

protected:
	/** @brief Called when the game starts */
	virtual void BeginPlay() override;

	/** @brief Called when the projectile is destroyed */
	virtual void Destroyed() override;

	/**
	 * @brief Called when sphere component overlaps another actor.
	 * 
	 * @param OverlappedComponent Component that triggered overlap.
	 * @param OtherActor Other actor overlapped.
	 * @param OtherComp Component of the other actor.
	 * @param OtherActorIndex Index of other body.
	 * @param bFromSweep True if overlap was from a sweep.
	 * @param SweepResult Hit result data from the overlap.
	 */
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherActorIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	/** @brief Projectile movement component */
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	/** @brief Damage effect spec handle applied on hit */
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	FGameplayEffectSpecHandle DamageEffectSpecHandle;
	
private:
	/** @brief Life span of projectile in seconds */
	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 15.f;
	
	/** @brief Collision sphere */
	TObjectPtr<USphereComponent> Sphere;

	/** @brief Niagara effect played on impact */
	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	/** @brief Sound played on impact */
	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSound;

	/** @brief Sound looped while projectile is active */
	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> LoopingSound;

	/** @brief Component handling looping sound playback */
	UPROPERTY()
	TObjectPtr<UAudioComponent> LoopingSoundComponent;
	
	/** @brief True if the projectile already hit something */
	bool bHit = false;
};
