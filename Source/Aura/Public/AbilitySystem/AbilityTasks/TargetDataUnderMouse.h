// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "TargetDataUnderMouse.generated.h"

/** Delegate broadcast when valid mouse target data is available */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature, const FGameplayAbilityTargetDataHandle&, DataHandle);

/**
 * @brief Ability task that provides target data from the mouse cursor.
 */
UCLASS()
class AURA_API UTargetDataUnderMouse : public UAbilityTask
{
	GENERATED_BODY()
public:

	/**
	 * @brief Creates and initializes a TargetDataUnderMouse task.
	 *
	 * @param OwningAbility The owning gameplay ability.
	 * @return New instance of UTargetDataUnderMouse.
	 */
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta = (DisplayName = "TargetDataUnderMouse", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	static UTargetDataUnderMouse* CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility);

	/** @brief Delegate fired when mouse target data is valid */
	UPROPERTY(BlueprintAssignable)
	FMouseTargetDataSignature ValidData;

private:

	/** @brief Starts the task and determines local or remote handling */
	virtual void Activate() override;

	/** @brief Collects hit result under mouse cursor and sends it to the server */
	void SendMouseCursorData();
	
	/**
	 * @brief Callback for replicated target data received from the client.
	 *
	 * @param DataHandle Target data received.
	 * @param ActivationTag Gameplay tag associated with activation.
	 */
	void OnTargetDataReplicatedCallback(const FGameplayAbilityTargetDataHandle& DataHandle, FGameplayTag ActivationTag);
};