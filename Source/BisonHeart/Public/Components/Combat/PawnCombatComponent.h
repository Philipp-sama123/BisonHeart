// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"


class ABisonHeartWeaponBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BISONHEART_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BisonHeart | Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ABisonHeartWeaponBase* InWeaponToRegister,
	                           bool bRegisterAsEquippedWeapon = false);
	
	UFUNCTION(BlueprintCallable, Category="BisonHeart | Combat")
	ABisonHeartWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
	
	UFUNCTION(BlueprintCallable, Category="BisonHeart | Combat")
	ABisonHeartWeaponBase* GetCharacterCurrentEquippedWeapon() const;
	
	UPROPERTY(BlueprintReadWrite, Category="BisonHeart | Combat")
	FGameplayTag CurrentEquippedWeaponTag;

private:
	TMap<FGameplayTag, ABisonHeartWeaponBase*> CharacterCarriedWeaponMap;
};
