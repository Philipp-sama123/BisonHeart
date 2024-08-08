// All Rights Reserved by @KrazyCatGames


#include "AbilitySystem/Abilities/BisonHeartHeroGameplayAbility.h"

#include "Characters/BisonHeartHeroCharacter.h"
#include "Controllers/BisonHeartHeroController.h"

ABisonHeartHeroCharacter* UBisonHeartHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedBisonHeartHeroCharacter.IsValid())
	{
		CachedBisonHeartHeroCharacter = Cast<ABisonHeartHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedBisonHeartHeroCharacter.IsValid() ? CachedBisonHeartHeroCharacter.Get() : nullptr;
}

ABisonHeartHeroController* UBisonHeartHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedBisonHeartHeroController.IsValid())
	{
		CachedBisonHeartHeroController = Cast<ABisonHeartHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedBisonHeartHeroController.IsValid() ? CachedBisonHeartHeroController.Get() : nullptr;
}

UHeroCombatComponent* UBisonHeartHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
