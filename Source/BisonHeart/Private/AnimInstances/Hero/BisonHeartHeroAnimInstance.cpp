// All Rights Reserved by @KrazyCatGames


#include "AnimInstances/Hero/BisonHeartHeroAnimInstance.h"

#include "Characters/BisonHeartHeroCharacter.h"

void UBisonHeartHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<ABisonHeartHeroCharacter>(OwningCharacter);
	}
}

void UBisonHeartHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration == true)
	{
		IdleElapsedTime = true;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
