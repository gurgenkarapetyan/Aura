// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

class UGameplayAbility;
class UGameplayEffect;

/** @brief Enum of available character classes */
UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	Elementalist,
	Warrior,
	Ranger
};

/**
 * @brief Default attribute info for a character class.
 */
USTRUCT(BlueprintType)
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()

	/**
	* @brief Default attribute info for a character class.
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;
};

/**
 * @brief Data asset holding default GameplayEffects for each character class.
 */
UCLASS()
class AURA_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	/**
	* @brief Gets the default info struct for a given character class.
	*
	* @param CharacterClass The character class type.
	* @return Default info struct for the class.
	*/
	FCharacterClassDefaultInfo GetClassDefaultInfo(ECharacterClass CharacterClass); 

	/** @brief Map of class types to their default info */
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TMap<ECharacterClass, FCharacterClassDefaultInfo> CharacterClassInformation;
	
	/** @brief GameplayEffect for secondary attributes common to all classes */
	UPROPERTY(EditDefaultsOnly, Category = "Commmon Class Defaults")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	/** @brief GameplayEffect for vital attributes common to all classes */
	UPROPERTY(EditDefaultsOnly, Category = "Commmon Class Defaults")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	/** @brief List of common abilities */
	UPROPERTY(EditDefaultsOnly, Category = "Commmon Class Defaults")
	TArray<TSubclassOf<UGameplayAbility>> CommonAbilities;

	/** 
	* @brief Curve Table that defines coefficients for damage calculation.
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Commmon Class Defaults|Damage")
	TObjectPtr<UCurveTable> DamageCalculationCoefficients;
};
