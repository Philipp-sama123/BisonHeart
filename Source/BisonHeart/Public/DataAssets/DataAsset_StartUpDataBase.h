// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UBisonHeartAbilitySystemComponent;
class UBisonHeartGameplayAbility;
/**
 * 
 */
UCLASS()
class BISONHEART_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UBisonHeartAbilitySystemComponent* InBisonHeartAscToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UBisonHeartGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UBisonHeartGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UBisonHeartGameplayAbility>>& InAbilitiesToGive, UBisonHeartAbilitySystemComponent* InBisonHeartAscToGive,
	                    int32 ApplyLevel = 1);
};
