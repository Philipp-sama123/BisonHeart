// All Rights Reserved by @KrazyCatGames


#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"

#include "DebugHelper.h"

void UBisonHeartAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UBisonHeartAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
	// ToDo; later
	Debug::Print("OnAbilityInputReleased");
	return;
}
