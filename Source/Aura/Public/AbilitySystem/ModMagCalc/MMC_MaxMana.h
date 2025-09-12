// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

/**
 * @brief Magnitude calculation for Max Mana.
 *
 * Captures Intelligence from the target and scales mana based on
 * Intelligence and player level.
 */
UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	/** @brief Default constructor sets up attribute capture */
	UMMC_MaxMana();

	/**
	 * @brief Calculates the base magnitude for Max Mana.
	 *
	 * @param Spec Gameplay effect spec containing source and target info.
	 * @return Calculated Max Mana value.
	 */
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	/** @brief Capture definition for Intelligence attribute */
	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;
};
