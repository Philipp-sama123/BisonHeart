// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "BisonHeartWeaponBase.h"
#include "BisonHeartTypes/BisonHeartStructTypes.h"
#include "BisonHeartHeroWeapon.generated.h"

UCLASS()
class BISONHEART_API ABisonHeartHeroWeapon : public ABisonHeartWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WeaponData")
	FBisonHeartHeroWeaponData HeroWeaponData;
};
