// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataAssets/DataAsset_StartUpDataBase.h"
#include "BisonHeartTypes/BisonHeartStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class BISONHEART_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UBisonHeartAbilitySystemComponent* InAscToGive, int32 ApplyLevel=1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData", meta=(TitleProperty="InputTag"))
	TArray<FBisonHeartHeroAbilitySet> HeroStartUpAbilitySets;
};
