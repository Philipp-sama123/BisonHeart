// Fill out your copyright notice in the Description page of Project Settings.

#include "BisonHeart/Public/BisonHeartGameplayTags.h"
#include "NativeGameplayTags.h"

namespace BisonHeartGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe_Left, "Player.Weapon.Axe.Left");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe_Right, "Player.Weapon.Axe.Right");
}
