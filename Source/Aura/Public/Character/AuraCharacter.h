// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * @brief Player-controlled Aura character.
 *
 * Initializes ASC/attributes for both server and client
 * and sets up camera components.
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	
public:
	/** @brief Constructor sets up movement and camera boom */
	AAuraCharacter();

	/**
	 * @brief Called when character is possessed by a controller.
	 * Initializes ability actor info on the server.
	 * 
	 * @param NewController New controller possessing this character.
	 */
	virtual void PossessedBy(AController* NewController) override;

	/**
	 * @brief Called when PlayerState is replicated.
	 * Initializes ability actor info on the client.
	 */
	virtual void OnRep_PlayerState() override;

	/**
	 * @brief Returns the current player level from PlayerState.
	 * 
	 * @return Player level.
	 */
	virtual int32 GetPlayerLevel() override;
	
private:
	/** @brief Initializes ability actor info (ASC, attributes, HUD) */
	virtual void InitAbilityActorInfo() override;
	
	/** @brief Camera boom for positioning follow camera */
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* CameraBoom;

	/** @brief Follow camera component */
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* FollowCamera;
};
