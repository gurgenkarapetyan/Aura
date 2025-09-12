// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * @brief Magnitude calculation for Max Health.
 *
 * Captures Vigor from the target and scales health based on
 * Vigor and player level.
 */
UCLASS()
class AURA_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	/** @brief Default constructor sets up attribute capture */
	UMMC_MaxHealth();

	/**
	 * @brief Calculates the base magnitude for Max Health.
	 *
	 * @param Spec Gameplay effect spec containing source and target info.
	 * @return Calculated Max Health value.
	 */
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	/** @brief Capture definition for Vigor attribute */
	FGameplayEffectAttributeCaptureDefinition VigorDef;
};
