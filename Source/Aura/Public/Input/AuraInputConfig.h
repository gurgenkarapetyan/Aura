// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AuraInputConfig.generated.h"

class UInputAction;

/**
 * @brief Struct mapping an input action to a gameplay tag.
 */
USTRUCT(BlueprintType)
struct FAuraInputAction
{
	GENERATED_BODY()
	
	/** @brief Input action asset */
	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction = nullptr;
	
	/** @brief Gameplay tag associated with the input */
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};

/**
 * @brief Data asset that stores ability input configuration.
 */
UCLASS()
class AURA_API UAuraInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:

	/**
	 * @brief Finds the input action associated with a gameplay tag.
	 *
	 * @param InputTag Gameplay tag to search for.
	 * @param bLogNotFound If true, logs when no action is found.
	 * @return Input action pointer, or nullptr if not found.
	 */
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false) const;

	/** @brief List of input action/tag pairs */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAuraInputAction> AbilityInputActions;
};
