// All Rights Reserved by @KrazyCatGames

#pragma once
#include "GameplayTagContainer.h"

#include "BisonHeartStructTypes.generated.h"

class UInputMappingContext;
class UBisonHeartGameplayAbility;
class UBisonHeartHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FBisonHeartHeroAbilitySet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBisonHeartGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};


USTRUCT(BlueprintType)
struct FBisonHeartHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UBisonHeartHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty="InputTag"))
	TArray<FBisonHeartHeroAbilitySet> DefaultWeaponAbilities;
};
