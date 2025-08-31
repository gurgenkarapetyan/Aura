// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UAuraInputConfig;
class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
class UAuraAbilitySystemComponent;
class USplineComponent;

struct FInputActionValue;
struct FGameplayTag;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();

	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	void CursorTrace();

	void Move(const FInputActionValue& InputActionValue);

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	void AutoRunning();
	
	UAuraAbilitySystemComponent* GetAuraAbilitySystemComponent();
	
private:
	UPROPERTY(EditAnywhere, Category = "Input")	
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")	
	TObjectPtr<UInputAction> MoveAction;

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;

	FHitResult CursorHit;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	FVector CachedDestination = FVector::ZeroVector;

	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;

	bool bAutoRunning = false;
	bool bTargeting = false;
	
	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
};
