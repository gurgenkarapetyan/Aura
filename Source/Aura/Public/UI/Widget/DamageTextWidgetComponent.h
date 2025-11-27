// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DamageTextWidgetComponent.generated.h"

/**
 * @brief user widget for displaying amount of damage
 * when enemy receives.
 *
 */
UCLASS()
class AURA_API UDamageTextWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	/**
	 * @brief set damage widget text
	 * 
	 * @param Damage amount of damage received
	 * @param bBlockedHit Indicates whether the hit was blocked.
	 * @param bCriticalHit Indicates whether the hit was a critical strike.
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetDamageText(float Damage, bool bBlockedHit, bool bCriticalHit);
};
