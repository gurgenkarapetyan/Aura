// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AuraAssetManager.generated.h"

/**
 * @brief Custom Asset Manager for Aura.
 *
 * Initializes gameplay tags and GAS globals
 * during initial loading.
 */
UCLASS()
class AURA_API UAuraAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	/**
	 * @brief Returns the Aura asset manager instance.
	 * @return Reference to AuraAssetManager.
	 */
	static UAuraAssetManager& Get();

protected:
	/** @brief Called during startup to initialize gameplay tags and GAS data */
	virtual void StartInitialLoading() override;
};
