// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * @brief Interface for combat-related functionality.
 */
class AURA_API ICombatInterface
{
	GENERATED_BODY()

public:
	/** @brief Returns the character’s level */
	virtual int32 GetPlayerLevel();

	/** @brief Returns the location of the combat socket */
	virtual FVector GetCombatSocketLocation();

	/**
	 * @brief Updates actor facing direction toward target.
	 * @param Target World position to face.
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateFacingTarget(const FVector& Target);

	/**
	 * @brief Montage to Play on hit reaction.
	 * 
	 * @return montage to be played.
	 */
	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	UAnimMontage* GetHitReactMontage();

	/**
	 * @brief Handles character death logic.
	 */
	virtual void Die() = 0;
};
