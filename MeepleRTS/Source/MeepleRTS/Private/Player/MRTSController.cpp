// Fill out your copyright notice in the Description page of Project Settings.


#include "MeepleRTS/Public/Player/MRTSController.h"
#include "EnhancedInputSubsystems.h"
#include "MeepleRTS/Public/Player/MRTSInputComponent.h"

AMRTSController::AMRTSController(): PossessedPawn(nullptr), MoveAction(nullptr), LookAction(nullptr),
                                    ResetViewAction(nullptr)
{
}

void AMRTSController::BeginPlay()
{
	Super::BeginPlay();
	
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
		}
	}

	PossessedPawn = GetPawn();
}

void AMRTSController::Move(const FInputActionValue& Value)
{
	const FVector2d DirectionValue = Value.Get<FVector2d>();

	// ORconst FRotator Rotation = PossessedPawn->GetActorRotation();
	
	const FRotator Rotation = ControlRotation;
	
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	// Move Forward
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	PossessedPawn->AddMovementInput(ForwardDirection, DirectionValue.Y);
	
	// Move Right
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	PossessedPawn->AddMovementInput(RightDirection, DirectionValue.X);
}

void AMRTSController::Look(const FInputActionValue& Value)
{
	
}

void AMRTSController::ResetView()
{
	UE_LOG(LogTemp, Warning, TEXT("Pressed Reset View"));
}

void AMRTSController::Ability()
{
	
}

void AMRTSController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UMRTSInputComponent* Input = CastChecked<UMRTSInputComponent>(InputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMRTSController::Move);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMRTSController::Look);
		Input->BindAction(ResetViewAction, ETriggerEvent::Triggered, this, &AMRTSController::ResetView);
		
		// TODO Set up modular ability input
	}
}
