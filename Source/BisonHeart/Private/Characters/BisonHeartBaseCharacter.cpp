// Fill out your copyright notice in the Description page of Project Settings.


#include "BisonHeart/Public/Characters/BisonHeartBaseCharacter.h"


ABisonHeartBaseCharacter::ABisonHeartBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false; // ground decals shouldn`t have an effect on the Character
}
