// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BisonHeartAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class BISONHEART_API UBisonHeartAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);
};
