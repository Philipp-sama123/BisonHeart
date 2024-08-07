// All Rights Reserved by @KrazyCatGames


#include "AnimInstances/BisonHeartCharacterAnimInstance.h"

#include "Characters/BisonHeartBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBisonHeartCharacterAnimInstance::NativeInitializeAnimation()
{
	//	Super::NativeInitializeAnimation();

	OwningCharacter = Cast<ABisonHeartBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UBisonHeartCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	//	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;
	bIsInAir = OwningMovementComponent->IsFalling();
}
