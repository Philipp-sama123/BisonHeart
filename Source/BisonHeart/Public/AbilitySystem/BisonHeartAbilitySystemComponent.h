// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BisonHeartAbilitySystemComponent.generated.h"

struct FBisonHeartHeroAbilitySet;
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

	UFUNCTION(BlueprintCallable, Category="BisonHEart | Ability", meta=(ApplyLevel="1"))
	void GrantHeroWeaponAbilities(const TArray<FBisonHeartHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);
};
