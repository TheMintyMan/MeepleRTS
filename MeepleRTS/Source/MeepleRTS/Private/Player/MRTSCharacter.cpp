// Fill out your copyright notice in the Description page of Project Settings.


#include "MeepleRTS/Public/Player/MRTSCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMRTSCharacter::AMRTSCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritYaw = false;
	CameraComp->bUsePawnControlRotation = false;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void AMRTSCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMRTSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotates the character
	FVector Velocity = GetVelocity();
	
	if (!Velocity.IsNearlyZero())
	{
		FRotator TargetRotation = Velocity.Rotation();
		
		FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, 10.0f);
		SetActorRotation(NewRotation);
	}

}