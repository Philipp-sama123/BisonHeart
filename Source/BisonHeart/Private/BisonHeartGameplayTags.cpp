// Fill out your copyright notice in the Description page of Project Settings.

#include "BisonHeart/Public/BisonHeartGameplayTags.h"
#include "NativeGameplayTags.h"

namespace BisonHeartGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxes, "InputTag.EquipAxes");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAxes, "InputTag.UnquipAxes");

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Axes, "Player.Ability.Equip.Axes");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Axes, "Player.Ability.Unequip.Axes");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe_Left, "Player.Weapon.Axe.Left");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe_Right, "Player.Weapon.Axe.Right");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Axes, "Player.Event.Equip.Axes");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Axes, "Player.Event.Unequip.Axes");
}
