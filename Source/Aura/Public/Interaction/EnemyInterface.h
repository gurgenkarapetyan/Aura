// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * @brief Interface for enemy highlighting functionality.
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

public:
	/** @brief Highlights the enemy actor */
	virtual void HighlightActor() = 0;

	/** @brief Removes highlight from the enemy actor */
	virtual void UnHighlightActor() = 0;
};
