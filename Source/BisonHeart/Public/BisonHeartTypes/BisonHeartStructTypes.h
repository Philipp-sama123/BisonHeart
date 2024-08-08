// All Rights Reserved by @KrazyCatGames

#pragma once

#include "BisonHeartStructTypes.generated.h"

class UBisonHeartHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FBisonHeartHeroWeaponData
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBisonHeartHeroLinkedAnimLayer> WeaponAnimLayerToLink;
	
};
