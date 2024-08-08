// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"


class ABisonHeartHeroWeapon;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BISONHEART_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BisonHeart | Combat")
	ABisonHeartHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
};
