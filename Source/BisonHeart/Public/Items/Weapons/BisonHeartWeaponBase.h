// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BisonHeartWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class BISONHEART_API ABisonHeartWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	ABisonHeartWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
	UBoxComponent* WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; };
};
