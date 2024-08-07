// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BisonHeartGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EBisonHeartAbilityActivationPolicy :uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class BISONHEART_API UBisonHeartGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                        const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category="BisonHeartAbility")
	EBisonHeartAbilityActivationPolicy AbilityActivationPolicy = EBisonHeartAbilityActivationPolicy::OnTriggered;
};
