// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BisonHeartGameplayAbility.h"
#include "BisonHeartHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class ABisonHeartHeroController;
class ABisonHeartHeroCharacter;
/**
 * 
 */
UCLASS()
class BISONHEART_API UBisonHeartHeroGameplayAbility : public UBisonHeartGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BisonHeartAbility | Ability")
	ABisonHeartHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="BisonHeartAbility | Ability")
	ABisonHeartHeroController* GetHeroControllerFromActorInfo();

	
	UFUNCTION(BlueprintPure, Category="BisonHeartAbility | Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
private:
	TWeakObjectPtr<ABisonHeartHeroCharacter> CachedBisonHeartHeroCharacter; // just holds a reference of it -- smart pointer (!)
	TWeakObjectPtr<ABisonHeartHeroController> CachedBisonHeartHeroController; // just holds a reference of it -- smart pointer (!)
};
