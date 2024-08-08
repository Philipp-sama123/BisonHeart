// All Rights Reserved by @KrazyCatGames


#include "Components/Combat/HeroCombatComponent.h"

#include "Items/Weapons/BisonHeartHeroWeapon.h"

ABisonHeartHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<ABisonHeartHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
