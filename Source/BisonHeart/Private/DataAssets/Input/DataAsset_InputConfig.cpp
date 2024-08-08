// Fill out your copyright notice in the Description page of Project Settings.


#include "BisonHeart/Public/DataAssets/Input/DataAsset_InputConfig.h"

class UInputAction;

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FBisonHeartInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
