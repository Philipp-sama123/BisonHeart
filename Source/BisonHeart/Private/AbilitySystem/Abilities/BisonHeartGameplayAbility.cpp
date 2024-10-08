// All Rights Reserved by @KrazyCatGames


#include "BisonHeart/Public/AbilitySystem/Abilities/BisonHeartGameplayAbility.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"

void UBisonHeartGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EBisonHeartAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UBisonHeartGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                            const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
                                            bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
	if (AbilityActivationPolicy == EBisonHeartAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* UBisonHeartGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UBisonHeartAbilitySystemComponent* UBisonHeartGameplayAbility::GetBisonHeartAbilitySystemComponentFromActorInfo() const
{
	return Cast<UBisonHeartAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
