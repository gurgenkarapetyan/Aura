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

	/**
	 * @brief Montage to Play on hit reaction.
	 * 
	 * @return montage to be played.
	 */
	virtual UAnimMontage* GetHitReactMontage_Implementation() override;

	/**
	 * @brief Handles character death logic.
	 */
	virtual void Die() override;

	/**
	 * @brief Multicast RPC that notifies all clients about this character's death.
	 */
	UFUNCTION(NetMulticast, Reliable)
	virtual void MulticastHandleDeath();
	
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

	/**
	 * @brief Starts dissolve effect on character and weapon mesh.
	 */
	void Dissolve();

	/**
	 * @brief Blueprint event to play dissolve timeline on a character material.
	 * @param DynamicMaterialInstance Dynamic material instance to animate.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void StartDissolveTimeLine(UMaterialInstanceDynamic* DynamicMaterialInstance);

	/**
	 * @brief Blueprint event to play dissolve timeline on a weapon material.
	 * @param DynamicMaterialInstance Dynamic material instance to animate.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void StartWeaponDissolveTimeLine(UMaterialInstanceDynamic* DynamicMaterialInstance);
	
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

	/* Dissolve Effects */
	
	/* @brief Material instance used for character dissolve effect */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UMaterialInstance> DissolveMaterialInstance;
	
	/* @brief Material instance used for weapon dissolve effect */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UMaterialInstance> WeaponDissolveMaterialInstance;

private:
	/** @brief List of startup abilities */
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	/** @brief hit react montage */
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UAnimMontage> HitReactMontage;
};
