// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"
#include "AuraProjectileSpell.generated.h"

class AAuraProjectile;

/**
 * @brief Gameplay ability that spawns and launches a projectile.
 */
UCLASS()
class AURA_API UAuraProjectileSpell : public UAuraGameplayAbility
{
	GENERATED_BODY()

protected:
	/**
	 * @brief Activates the projectile ability.
	 *
	 * @param Handle Ability spec handle.
	 * @param ActorInfo Actor info for the ability owner.
	 * @param ActivationInfo Activation data including prediction keys.
	 * @param TriggerEventData Optional event data that triggered the ability.
	 */
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	/**
	 * @brief Spawns a projectile from the combat socket towards a target location.
	 *
	 * @param ProjectileTargetLocation World-space target location for the projectile.
	 */
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& ProjectileTargetLocation);

	/** @brief Class of projectile to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AAuraProjectile> ProjectileClass;

	/** @brief Damage effect applied when the projectile hits a target */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
