// All Rights Reserved by @KrazyCatGames

#pragma once

#include "CoreMinimal.h"
#include "BisonHeartHeroAnimInstance.h"
#include "AnimInstances/BisonHeartBaseAnimInstance.h"
#include "BisonHeartHeroLinkedAnimLayer.generated.h"

class UBisonHeartHeroAnimInstance;
/**
 * 
 */
UCLASS()
class BISONHEART_API UBisonHeartHeroLinkedAnimLayer : public UBisonHeartBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	UBisonHeartHeroAnimInstance* GetHeroAnimInstance() const;
};

inline UBisonHeartHeroAnimInstance* UBisonHeartHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UBisonHeartHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
