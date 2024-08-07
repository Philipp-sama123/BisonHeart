// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BisonHeartWeaponBase.generated.h"

UCLASS()
class BISONHEART_API ABisonHeartWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABisonHeartWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
