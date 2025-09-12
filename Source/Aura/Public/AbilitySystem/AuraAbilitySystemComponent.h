// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

/** @brief Delegate for broadcasting asset tags from applied effects */
DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /*AsssetTags*/)

/**
 * @brief Custom AbilitySystemComponent for Aura.
 *
 * Handles ability input mapping, granting startup abilities,
 * and broadcasting effect asset tags.
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	/** @brief Called when AbilityActorInfo is set up */
	void AbilityActorInfoSet();

	/** @brief Broadcasts asset tags from applied gameplay effects */
	FEffectAssetTags EffectAssetTags;

	/**
	 * @brief Grants startup abilities to the character.
	 *
	 * @param StartupAbilities List of abilities to grant.
	 */
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);

	
	/**
	 * @brief Handles ability input tag pressed.
	 *
	 * @param InputTag Tag representing the pressed input.
	 */
	void AbilityInputTagHeld(const FGameplayTag& InputTag);

	/**
	 * @brief Handles ability input tag released.
	 *
	 * @param InputTag Tag representing the released input.
	 */
	void AbilityInputTagReleased(const FGameplayTag& InputTag);
	
protected:
	/**
	 * @brief Client RPC called when a gameplay effect is applied.
	 *
	 * @param AbilitySystemComponent ASC where the effect was applied.
	 * @param EffectSpec The gameplay effect spec.
	 * @param ActiveEffectHandle Handle of the active effect.
	 */
	UFUNCTION(Client, Reliable)
	void ClientEffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
