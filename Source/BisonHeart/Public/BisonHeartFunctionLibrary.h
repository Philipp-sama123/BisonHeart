// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BisonHeartFunctionLibrary.generated.h"

class UBisonHeartAbilitySystemComponent;

UENUM()
enum class EBisonHeartConfirmType : uint8
{
	Yes,
	No
};

/**
 * 
 */
UCLASS()
class BISONHEART_API UBisonHeartFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UBisonHeartAbilitySystemComponent* NativeGetBisonHeartAscFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="BisonHeart | FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category="BisonHeart | FunctionLibrary")
	static void RemoveGameplayTagToActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary",
		meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EBisonHeartConfirmType& OutConfirmType);
};
