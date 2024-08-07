// Fill out your copyright notice in the Description page of Project Settings.


#include "BisonHeart/Public/Characters/BisonHeartHeroCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "BisonHeart/Public/BisonHeartGameplayTags.h"
#include "BisonHeart/Public/Components/BisonHeartInputComponent.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "DataAssets/DataAsset_StartUpDataBase.h"

ABisonHeartHeroCharacter::ABisonHeartHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(40.f, 90.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 50.f, 50.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void ABisonHeartHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartupData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartupData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(BisonHeartAbilitySystemComponent);
		}
	}
}

void ABisonHeartHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Check if a valid Data asset is assigned!"));

	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	check(Subsystem);
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UBisonHeartInputComponent* MainInputComponent = CastChecked<UBisonHeartInputComponent>(PlayerInputComponent);
	MainInputComponent->BindNativeInputAction(InputConfigDataAsset, BisonHeartGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this,
	                                          &ThisClass::Input_Move);
	MainInputComponent->BindNativeInputAction(InputConfigDataAsset, BisonHeartGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this,
	                                          &ThisClass::Input_Look);

	MainInputComponent->BindNativeInputAction(InputConfigDataAsset, BisonHeartGameplayTags::InputTag_Jump, ETriggerEvent::Started, this,
	                                          &ThisClass::Jump);
	MainInputComponent->BindNativeInputAction(InputConfigDataAsset, BisonHeartGameplayTags::InputTag_Jump, ETriggerEvent::Started, this,
	                                          &ThisClass::StopJumping);
}

void ABisonHeartHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABisonHeartHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2d MovementVector = InputActionValue.Get<FVector2d>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABisonHeartHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2d LookAxisVector = InputActionValue.Get<FVector2d>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
