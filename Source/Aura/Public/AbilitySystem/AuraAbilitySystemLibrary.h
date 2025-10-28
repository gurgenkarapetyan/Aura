// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

struct FGameplayEffectContextHandle;
class UCharacterClassInfo;
enum class ECharacterClass : uint8;
class UAttributeMenuWidgetController;
class UOverlayWidgetController;

/**
 * @brief Static helper library for Aura's AbilitySystem.
 *
 * Provides utility functions for widget controllers and
 * initializing default attributes.
 */
UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	 * @brief Gets the overlay widget controller for the local player.
	 *
	 * @param WorldContextObject World context.
	 * @return Overlay widget controller, or nullptr if not found.
	 */
	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary|WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	/**
	 * @brief Gets the attribute menu widget controller for the local player.
	 *
	 * @param WorldContextObject World context.
	 * @return Attribute menu widget controller, or nullptr if not found.
	 */
	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary|WidgetController")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
	
	/**
	 * @brief Initializes default attributes for a character.
	 *
	 * @param WorldContextObject World context.
	 * @param CharacterClass The class type of the character.
	 * @param Level Character level.
	 * @param ASC AbilitySystemComponent to apply attributes to.
	 */
	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);

	/**
	* @brief Initializes start up abilities.
	*
	* @param WorldContextObject World context.
	* @param ASC AbilitySystemComponent to apply attributes to.
	*/
	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|CharacterClassDefaults")
	static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC);

	/**
	 * @brief Retrieves the Character Class Info asset from the active Aura Game Mode.
	 *
	 * @param WorldContextObject The world context used to access the current Game Mode.
	 * @return Pointer to the UCharacterClassInfo asset if found; nullptr otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|CharacterClassDefaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

	/**
	 * @brief Checks if the given Gameplay Effect Context represents a blocked hit.
	 *
	 * @param EffectContextHandle Handle to the Gameplay Effect Context to check.
	 * @return true if the hit was blocked, false otherwise.
	 */
	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary|GameplayEffects")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);

	/**
	 * @brief Checks if the given Gameplay Effect Context represents a critical hit.
	 *
	 * @param EffectContextHandle Handle to the Gameplay Effect Context to check.
	 * @return true if the hit was critical, false otherwise.
	 */	
	UFUNCTION(BlueprintPure, Category = "AuraAbilitySystemLibrary|GameplayEffects")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);

	/**
	 * @brief Sets the blocked hit flag on the specified Gameplay Effect Context.
	 *
	 * @param EffectContextHandle Handle to the Gameplay Effect Context to modify.
	 * @param IsBlockedHit Whether the hit should be marked as blocked.
	 */
	UFUNCTION(BlueprintCallable,  Category = "AuraAbilitySystemLibrary|GameplayEffects")
	static void SetIsBlockedHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool IsBlockedHit);

	/**
	 * @brief Sets the critical hit flag on the specified Gameplay Effect Context.
	 *
	 * @param EffectContextHandle Handle to the Gameplay Effect Context to modify.
	 * @param IsCriticalHit Whether the hit should be marked as critical.
	 */
	UFUNCTION(BlueprintCallable,  Category = "AuraAbilitySystemLibrary|GameplayEffects")
	static void SetIsCriticalHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool IsCriticalHit);
};
