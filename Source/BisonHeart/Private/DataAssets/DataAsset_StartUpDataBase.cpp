// All Rights Reserved by @KrazyCatGames


#include "DataAssets/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/BisonHeartGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UBisonHeartAbilitySystemComponent* InBisonHeartAscToGive, int32 ApplyLevel)
{
	check(InBisonHeartAscToGive);

	GrantAbilities(ActivateOnGivenAbilities, InBisonHeartAscToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InBisonHeartAscToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UBisonHeartGameplayAbility>>& InAbilitiesToGive,
                                                UBisonHeartAbilitySystemComponent* InBisonHeartAscToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UBisonHeartGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InBisonHeartAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InBisonHeartAscToGive->GiveAbility(AbilitySpec);
	}
}
