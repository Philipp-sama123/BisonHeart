// Fill out your copyright notice in the Description page of Project Settings.


#include "BisonHeart/Public/Characters/BisonHeartBaseCharacter.h"

#include "AbilitySystem/BisonHeartAbilitySystemComponent.h"
#include "AbilitySystem/BisonHeartAttributeSet.h"


ABisonHeartBaseCharacter::ABisonHeartBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false; // ground decals shouldn`t have an effect on the Character

	BisonHeartAbilitySystemComponent = CreateDefaultSubobject<UBisonHeartAbilitySystemComponent>(TEXT("BisonHeartAbilitySystemComponent"));
	BisonHeartAttributeSet = CreateDefaultSubobject<UBisonHeartAttributeSet>(TEXT("BisonHeartAttributeSet"));
}

UAbilitySystemComponent* ABisonHeartBaseCharacter::GetAbilitySystemComponent() const
{
	return GetBisonHeartAbilitySystemComponent();
}

void ABisonHeartBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (BisonHeartAbilitySystemComponent)
	{
		BisonHeartAbilitySystemComponent->InitAbilityActorInfo(this, this); // sets the Actor Info
	}

	ensureMsgf(!CharacterStartupData.IsNull(), TEXT("Assign Startup Data to %s"), *GetName()); // Makro for checking the Data
}
