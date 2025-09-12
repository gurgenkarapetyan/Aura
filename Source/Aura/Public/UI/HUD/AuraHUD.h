// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAttributeMenuWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAuraUserWidget;

/**
 * @brief Custom HUD for Aura.
 *
 * Initializes overlay widgets and provides access
 * to widget controllers.
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
	/**
	 * @brief Initializes the overlay widget.
	 * @param PC Owning player controller.
	 * @param PS Player state.
	 * @param ASC Ability system component.
	 * @param AS Attribute set.
	 */
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	/**
	 * @brief Gets or creates the overlay widget controller.
	 * @param WCParams Parameters for widget controller.
	 * @return Overlay widget controller.
	 */
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	/**
	* @brief Gets or creates the attribute menu widget controller
	* @param WCParams Parameters for widget controller.
	 * @return Attribute menu widget controller.
	 */
	UAttributeMenuWidgetController* GetUAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

private:
	/** @brief Overlay widget instance */
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	
	/** @brief Overlay widget class */
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	/** @brief Overlay widget controller instance */
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	/** @brief Overlay widget controller class */
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	/** @brief Attribute menu widget controller instance */
	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	/** @brief Attribute menu widget controller class */
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
