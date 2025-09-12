// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * @brief Custom PlayerState for Aura.
 *
 * Owns ASC, attribute set, and replicates level.
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState,  public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	/** @brief Constructor sets up ASC and attributes */
	AAuraPlayerState();

	/** @brief Sets up replicated properties */
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	/** @brief Returns this player’s ASC */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; 

	/** @brief Returns AttributeSet */
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	/** @brief Returns Player Level */
	FORCEINLINE int32 GetPlayerLevel() const { return Level; }
	
private:
	/** @brief Called when Level is replicated */
	UFUNCTION()
	void OnRep_Level(int32 OldLevel) const;
	
protected:
	/** @brief Ability system component */
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	/** @brief Attribute set */
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

private:
	/** @brief Player level */
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
	int32 Level = 1;
};
