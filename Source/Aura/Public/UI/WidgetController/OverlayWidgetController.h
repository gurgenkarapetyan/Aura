// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

class UAuraUserWidget;

struct FGameplayTag;
struct FOnAttributeChangeData;

/**
 * @brief UI row for displaying messages in overlay.
 */
USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	/** @brief Message tag used for lookup */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();
	
	/** @brief Displayed message text */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();

	/** @brief Widget class used for the message */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAuraUserWidget> MessageWidget;

	/** @brief Image shown with the message */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
};

/** @brief Delegate for broadcasting attribute value changes */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttibuteChangedSignature, float, NewValue);

/** @brief Delegate for broadcasting widget row messages */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

/**
 * @brief Widget controller for overlay HUD.
 *
 * Broadcasts health/mana changes and gameplay messages.
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	
public:
	/** @brief Broadcasts initial values */
	virtual void BroadcastInitialValues() override;

	/** @brief Binds ASC callbacks for attributes and tags */
	virtual void BindCallbacksToDependencies() override;

protected:
	/**
	 * @brief Finds a data table row by gameplay tag.
	 * @tparam T Row struct type.
	 * @param DataTable Data table reference.
	 * @param Tag Gameplay tag used as row key.
	 * @return Pointer to row struct, or nullptr if not found.
	 */
	template<typename T>
	static T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
	
public:
	/** @brief Delegate fired when health changes */
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttibuteChangedSignature OnHealthChanged;
	
	/** @brief Delegate fired when max health changes */
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttibuteChangedSignature OnMaxHealthChanged;

	/** @brief Delegate fired when mana changes */
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttibuteChangedSignature OnManaChanged;

	/** @brief Delegate fired when max mana changes */
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FAttibuteChangedSignature OnMaxManaChanged;

	/** @brief Delegate fired when a gameplay message is received */
	UPROPERTY(BlueprintAssignable, Category = "GAS|Messages")
	FMessageWidgetRowSignature MessageWidgetRowDelegate;
	
protected:
	/** @brief Data table for gameplay messages */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
