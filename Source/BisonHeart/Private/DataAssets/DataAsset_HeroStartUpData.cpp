// All Rights Reserved by @KrazyCatGames


#include "BisonHeart/Public/DataAssets/DataAsset_HeroStartUpData.h"

#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/BisonHeartGameplayAbility.h"

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UBisonHeartAbilitySystemComponent* InAscToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InAscToGive, ApplyLevel);

	for (const FBisonHeartHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag); // very important
		
		InAscToGive->GiveAbility(AbilitySpec);
	}
}
