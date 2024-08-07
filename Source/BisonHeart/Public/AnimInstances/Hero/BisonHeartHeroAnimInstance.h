// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BisonHeartCharacterAnimInstance.h"
#include "BisonHeartHeroAnimInstance.generated.h"

class ABisonHeartHeroCharacter;

UCLASS()
class BISONHEART_API UBisonHeartHeroAnimInstance : public UBisonHeartCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData | References")
	ABisonHeartHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData | LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimData | LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime;
};
