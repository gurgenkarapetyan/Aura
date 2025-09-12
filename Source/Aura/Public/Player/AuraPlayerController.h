// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UDamageTextWidgetComponent;
class UAuraInputConfig;
class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
class UAuraAbilitySystemComponent;
class USplineComponent;

struct FInputActionValue;
struct FGameplayTag;

/**
 * @brief Player controller for Aura.
 *
 * Handles input, cursor tracing, autorun movement,
 * and ability input tag binding.
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/** @brief Constructor sets defaults */
	AAuraPlayerController();

	/** @brief Ticks controller logic each frame */
	virtual void PlayerTick(float DeltaTime) override;

	/**
	 * @brief Client RPC that displays floating damage numbers on character.
	 * @param DamageAmount Amount of damage to show.
	 * @param TargetCharacter Character above which text will be displayed
	 */
	UFUNCTION(Client, Reliable)
	void ShowDamageNumber(float DamageAmount, ACharacter* TargetCharacter);
	
protected:
	/** @brief Called when play begins */
	virtual void BeginPlay() override;

	/** @brief Sets up input bindings */
	virtual void SetupInputComponent() override;

private:
	/** @brief Performs cursor trace and handles enemy highlighting */
	void CursorTrace();

	/** @brief Handles movement input */
	void Move(const FInputActionValue& InputActionValue);

	/** @brief Sets shift state to pressed */
	void ShiftPressed() { bShiftKeyDown = true; }
	/** @brief Sets shift state to released */
	void ShiftReleased() { bShiftKeyDown = false; }
	
	/** @brief Handles ability input pressed */
	void AbilityInputTagPressed(FGameplayTag InputTag);
	/** @brief Handles ability input released */
	void AbilityInputTagReleased(FGameplayTag InputTag);
	/** @brief Handles ability input held */
	void AbilityInputTagHeld(FGameplayTag InputTag);

	/** @brief Processes autorun movement */
	void AutoRunning();
	
	/** @brief Returns this controller’s Aura ASC */
	UAuraAbilitySystemComponent* GetAuraAbilitySystemComponent();
	
private:
	/** @brief Input mapping context */
	UPROPERTY(EditAnywhere, Category = "Input")	
	TObjectPtr<UInputMappingContext> AuraContext;

	/** @brief Movement input action */
	UPROPERTY(EditAnywhere, Category = "Input")	
	TObjectPtr<UInputAction> MoveAction;

	/** @brief Shift input action */
	UPROPERTY(EditAnywhere, Category = "Input")	
	TObjectPtr<UInputAction> ShiftAction;

	/** @brief True if shift key is down */
	bool bShiftKeyDown = false;
	
	/** @brief Last highlighted enemy actor */
	TScriptInterface<IEnemyInterface> LastActor;

	/** @brief Currently highlighted enemy actor */
	TScriptInterface<IEnemyInterface> ThisActor;

	/** @brief Cached cursor hit result */
	FHitResult CursorHit;
	
	/** @brief Input configuration asset */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	/** @brief Cached Aura ASC pointer */
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	/** @brief Cached autorun destination */
	FVector CachedDestination = FVector::ZeroVector;

	/** @brief Time following target with LMB held */
	float FollowTime = 0.f;

	/** @brief Max time considered a short press */
	float ShortPressThreshold = 0.5f;

	/** @brief True if autorunning */
	bool bAutoRunning = false;

	/** @brief True if targeting an actor */
	bool bTargeting = false;
	
	/** @brief Acceptance radius for autorun stop */
	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	/** @brief Spline used for autorun pathing */
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	/** @brief WidgetComponent used to spawn amount of damage character receives */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageTextWidgetComponent> DamageTextComponentClass;
};
