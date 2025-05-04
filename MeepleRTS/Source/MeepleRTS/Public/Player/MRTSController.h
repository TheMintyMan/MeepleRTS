// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "MRTSController.generated.h"

/**
 * 
 */
UCLASS()
class MEEPLERTS_API AMRTSController : public APlayerController
{
	GENERATED_BODY()

	AMRTSController();
	
protected:
	
	UPROPERTY()
	APawn* PossessedPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* ResetViewAction;

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void ResetView();
	
	// Any sort of Ability will be run through here. Runs the ability through a Gameplay Tag.
	void Ability();

	void SetupInputComponent() override;
	
	
};

