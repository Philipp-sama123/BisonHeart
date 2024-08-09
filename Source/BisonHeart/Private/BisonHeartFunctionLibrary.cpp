// All Rights Reserved by @KrazyCatGames


#include "BisonHeartFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"

UBisonHeartAbilitySystemComponent* UBisonHeartFunctionLibrary::NativeGetBisonHeartAscFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<UBisonHeartAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UBisonHeartFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UBisonHeartAbilitySystemComponent* ASC = NativeGetBisonHeartAscFromActor(InActor);
	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UBisonHeartFunctionLibrary::RemoveGameplayTagToActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UBisonHeartAbilitySystemComponent* ASC = NativeGetBisonHeartAscFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UBisonHeartFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UBisonHeartAbilitySystemComponent* ASC = NativeGetBisonHeartAscFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UBisonHeartFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EBisonHeartConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EBisonHeartConfirmType::Yes : EBisonHeartConfirmType::No;
}
