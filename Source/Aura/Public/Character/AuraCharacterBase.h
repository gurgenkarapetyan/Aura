// Copyright Gurgen Karapetyan

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	FORCEINLINE USkeletalMeshComponent* GetWeapon() const { return Weapon; }
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;	
};
