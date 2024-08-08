// All Rights Reserved by @KrazyCatGames


#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/BisonHeartGameplayAbility.h"
#include "DebugHelper.h"
#include "BisonHeartTypes/BisonHeartStructTypes.h"

void UBisonHeartAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UBisonHeartAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
	// ToDo; later
	Debug::Print("OnAbilityInputReleased");
	return;
}

void UBisonHeartAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FBisonHeartHeroAbilitySet>& InDefaultWeaponAbilities,
                                                                 int32 ApplyLevel,
                                                                 TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle)
{
	if (InDefaultWeaponAbilities.IsEmpty()) return;

	for (const FBisonHeartHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		OutGrantedAbilitySpecHandle.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UBisonHeartAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	if (InSpecHandlesToRemove.IsEmpty()) return;

	for (const FGameplayAbilitySpecHandle SpecHandle : InSpecHandlesToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}
	InSpecHandlesToRemove.Empty();
}
