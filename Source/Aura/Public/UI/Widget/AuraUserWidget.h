// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * @brief Base user widget for Aura.
 *
 * Stores a widget controller reference and notifies
 * when the controller is set.
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * @brief Sets the widget controller.
	 * @param InWidgetController Controller object to assign.
	 */
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
protected:
	/** @brief Called when widget controller is set */
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
public:
	/** @brief Widget controller assigned to this widget */
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
};
