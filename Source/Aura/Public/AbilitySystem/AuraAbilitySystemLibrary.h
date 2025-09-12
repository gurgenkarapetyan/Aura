// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

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
};
