// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/** @brief Macro to simplify attribute accessors */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * @brief Helper struct for capturing effect source/target properties.
 */
USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}
	
	/** @brief Effect context handle */
	FGameplayEffectContextHandle EffectContextHandle;

	/** @brief Source ASC */
	UPROPERTY() UAbilitySystemComponent* SourceASC = nullptr;

	/** @brief Source avatar actor */
	UPROPERTY() AActor* SourceAvatarActor = nullptr;

	/** @brief Source controller */
	UPROPERTY() AController* SourceController = nullptr;

	/** @brief Source character */
	UPROPERTY() ACharacter* SourceCharacter = nullptr;

	/** @brief Target ASC */
	UPROPERTY() UAbilitySystemComponent* TargetASC = nullptr;

	/** @brief Target avatar actor */
	UPROPERTY() AActor* TargetAvatarActor = nullptr;

	/** @brief Target controller */
	UPROPERTY() AController* TargetController = nullptr;

	/** @brief Target character */
	UPROPERTY() ACharacter* TargetCharacter = nullptr;
};

/** @brief Alias for static function pointers used in tag mapping */
template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * @brief Attribute set for Aura characters.
 *
 * Defines primary, secondary, and vital attributes with replication
 * and effect execution hooks.
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	/** @brief Constructor, initializes tag-to-attribute map */
	UAuraAttributeSet();

	/** @brief Sets up replication for attributes */
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	/** @brief Called before an attribute is changed */
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	/** @brief Called after a gameplay effect modifies attributes */
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

private:

	/**
	 * @brief Collects source/target data from an effect callback.
	 *
	 * @param Data Effect callback data.
	 * @param Props Out struct populated with effect properties.
	 */
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data,  FEffectProperties& Props) const;

	/**
	 * @brief Displays floating damage text for the target.
	 *
	 * Spawns a damage number on the target character
	 *
	 * @param Props Effect properties containing source and target info.
	 * @param Damage Amount of damage dealt.
	 */
	void ShowFloatingText(const FEffectProperties& Props, float Damage) const;
	
	/** @brief Replication notification for Strength */
	UFUNCTION() void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	
	/** @brief Replication notification for Intelligence */
	UFUNCTION() void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	
	/** @brief Replication notification for Resilience */
	UFUNCTION() void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	
	/** @brief Replication notification for Vigor */
	UFUNCTION() void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	
	/** @brief Replication notification for Armor */
	UFUNCTION() void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	
	/** @brief Replication notification for Armor Penetration */
	UFUNCTION() void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;
	
	/** @brief Replication notification for Block Chance */
	UFUNCTION() void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;
	
	/** @brief Replication notification for Critical Hit Chance */
	UFUNCTION() void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;
	
	/** @brief Replication notification for Critical Hit Damage */
	UFUNCTION() void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;
	
	/** @brief Replication notification for Critical Hit Resistance */
	UFUNCTION() void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;
	
	/** @brief Replication notification for Health Regeneration */
	UFUNCTION() void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	
	/** @brief Replication notification for Mana Regeneration */
	UFUNCTION() void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;
	
	/** @brief Replication notification for Max Health */
	UFUNCTION() void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	/** @brief Replication notification for Max Mana */
	UFUNCTION() void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	/** @brief Replication notification for Health */
	UFUNCTION() void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	/** @brief Replication notification for Mana */
	UFUNCTION() void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
public:
	/**
	 * Primary Attributes
	 */
	
	/** @brief Strength (primary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	/** @brief Intelligence (primary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	/** @brief Resilience (primary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	/** @brief Vigor (primary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	/**
	* Secondary Attributes
	*/
	
	/** @brief Armor (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);
	
	/** @brief Armor penetration (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration);
	
	/** @brief Block chance (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);
	
	/** @brief Critical hit chance (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance);
	
	/** @brief Critical hit damage (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage);
	
	/** @brief Critical hit resistance (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance);
	
	/** @brief Health regeneration rate (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration);
	
	/** @brief Mana regeneration rate (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration);
	
	/** @brief Maximum health (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	
	/** @brief Maximum mana (secondary attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	/**
	 * Vital Attributes
	 */
	
	/** @brief Current health (vital attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	
	/** @brief Current mana (vital attribute) */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	/**
	 * Meta Attributes
	 */
	
	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, IncomingDamage);
	
	/** @brief Map of gameplay tags to attribute accessors */
	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;
};
