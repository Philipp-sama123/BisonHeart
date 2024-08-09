// All Rights Reserved by @KrazyCatGames


#include "BisonHeartTypes/BisonHeartStructTypes.h"

#include "AbilitySystem/Abilities/BisonHeartHeroGameplayAbility.h"

bool FBisonHeartHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
