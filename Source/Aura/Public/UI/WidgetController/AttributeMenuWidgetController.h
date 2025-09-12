// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UAttributeInfo;

struct FGameplayTag;
struct FGameplayAttribute;
struct FAuraAttributeInfo;

/** @brief Delegate for broadcasting attribute info */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeInfoSignature, const FAuraAttributeInfo&, Info);

/**
 * @brief Widget controller for the attribute menu.
 *
 * Binds attribute changes and broadcasts their info.
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	/** @brief Broadcasts initial attribute values */
	virtual void BroadcastInitialValues() override;
	
	/** @brief Binds attribute change callbacks */
	virtual void BindCallbacksToDependencies() override;

private:
	/**
	 * @brief Broadcasts info for a given attribute.
	 * @param AttributeTag Tag identifying the attribute.
	 * @param Attribute Attribute handle used for value lookup.
	 */
	void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const;
	
public:
	/** @brief Delegate fired when attribute info is updated */
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttributeInfoSignature AttributeInfoDelegate;

protected:
	/** @brief Attribute info data asset */
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> AttributeInfo;
};
