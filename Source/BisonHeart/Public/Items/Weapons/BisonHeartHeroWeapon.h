// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "BisonHeartWeaponBase.h"
#include "BisonHeartHeroWeapon.generated.h"

UCLASS()
class BISONHEART_API ABisonHeartHeroWeapon : public ABisonHeartWeaponBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABisonHeartHeroWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
