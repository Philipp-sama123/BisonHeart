// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BisonHeartBaseCharacter.generated.h"

class UBisonHeartAttributeSet;
class UBisonHeartAbilitySystemComponent;

UCLASS()
class BISONHEART_API ABisonHeartBaseCharacter : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABisonHeartBaseCharacter();
	//~ Begin IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

protected:
	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	UBisonHeartAbilitySystemComponent* BisonHeartAbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	UBisonHeartAttributeSet* BisonHeartAttributeSet;

public:
	FORCEINLINE UBisonHeartAttributeSet* GetBisonHeartAttributeSet() const { return BisonHeartAttributeSet; };
	FORCEINLINE UBisonHeartAbilitySystemComponent* GetBisonHeartAbilitySystemComponent() const { return BisonHeartAbilitySystemComponent; }
};
