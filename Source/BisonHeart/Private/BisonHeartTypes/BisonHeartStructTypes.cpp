// All Rights Reserved by @KrazyCatGames


#include "BisonHeartTypes/BisonHeartStructTypes.h"

#include "AbilitySystem/Abilities/BisonHeartGameplayAbility.h"

bool FBisonHeartHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
