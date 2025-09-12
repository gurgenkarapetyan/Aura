// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;

/**
 * @brief Enemy character class.
 *
 * Initializes ASC and attributes, manages health bar widget,
 * and implements highlighting and combat interfaces.
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	/** @brief Constructor sets mesh, ASC, and health bar defaults */
	AAuraEnemy();

	/** @brief Highlights this actor (outline) */
	virtual void HighlightActor() override;

	/** @brief Removes highlight from this actor */
	virtual void UnHighlightActor() override;

	/**
	 * @brief Returns the enemy's level.
	 *
	 * @return Character level.
	 */
	virtual int32 GetPlayerLevel() override;

protected:
	/** @brief Called when play begins */
	virtual void BeginPlay() override;

	/** @brief Initializes ASC and attributes */
	virtual void InitAbilityActorInfo() override;

	/** @brief Applies class-specific default attributes */
	virtual void InitializeDefaultAttributes() const;
	
public:
	/** @brief Broadcast when health changes */
	UPROPERTY(BlueprintAssignable)
	FAttibuteChangedSignature OnHealthChanged;

	/** @brief Broadcast when max health changes */
	UPROPERTY(BlueprintAssignable)
	FAttibuteChangedSignature OnMaxHealthChanged;
	
protected:
	/** @brief Health bar widget component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
	
	/** @brief Enemy level */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults", meta = (AllowPrivateAccess = "true"))
	int32 Level = 1;

	/** @brief Enemy character class type */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults", meta = (AllowPrivateAccess = "true"))
	ECharacterClass CharacterClass = ECharacterClass::Warrior;
};
