// All Rights Reserved by @KrazyCatGames


#include "Items/Weapons/BisonHeartWeaponBase.h"

#include "Components/BoxComponent.h"

ABisonHeartWeaponBase::ABisonHeartWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());

	WeaponCollisionBox->SetBoxExtent(FVector(20.F));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
