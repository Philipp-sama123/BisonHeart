// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BisonHeartBaseAnimInstance.h"
#include "BisonHeartCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class ABisonHeartBaseCharacter;
/**
 * 
 */
UCLASS()
class BISONHEART_API UBisonHeartCharacterAnimInstance : public UBisonHeartBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY()
	ABisonHeartBaseCharacter* OwningCharacter;
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData | LocomotionData")
	float GroundSpeed;
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData | LocomotionData")
	bool bHasAcceleration;
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData | LocomotionData")
	bool bIsInAir;
	
};
