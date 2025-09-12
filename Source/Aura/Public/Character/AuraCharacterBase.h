// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UAbilitySystemComponent;
class UAttributeSet;

/**
 * @brief Base class for Aura characters (player and enemy).
 *
 * Implements ASC interface, initializes default attributes,
 * applies startup abilities, and provides combat socket access.
 */
UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	/** @brief Constructor sets defaults */
	AAuraCharacterBase();

	/** @brief Returns this character's ASC */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; 

	/** @brief Returns this character's attribute set */
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
protected:
	/** @brief Called when play begins */
	virtual void BeginPlay() override;

	/** @brief Initializes ability actor info (ASC/Attributes) */
	virtual void InitAbilityActorInfo();

	/** @brief Applies default attributes to self */
	virtual void InitializeDefaultAttributes() const;

	/**
	 * @brief Applies a gameplay effect to self.
	 *
	 * @param GameplayEffect Effect to apply.
	 * @param Level Effect level.
	 */
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffect, float Level) const;

	/** @brief Grants startup abilities to this character */
	void AddCharacterAbilities();

	/**
	 * @brief Returns the world-space location of the combat socket.
	 *
	 * @return Socket location vector.
	 */
	virtual FVector GetCombatSocketLocation() override;
	
protected:
	/** @brief Weapon mesh */
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	/** @brief Name of the weapon tip socket */
	UPROPERTY(EditAnywhere, Category = "Combat")
	FName WeaponTipSocketName;
	
	/** @brief Ability System Component */
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	/** @brief Attribute set instance */
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	/** @brief Default primary attributes effect */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	/** @brief Default secondary attributes effect */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	
	/** @brief Default vital attributes effect */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

private:
	/** @brief List of startup abilities */
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
