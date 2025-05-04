// Fill out your copyright notice in the Description page of Project Settings.


#include "MeepleRTS/Public/Player/MRTSPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMRTSPawn::AMRTSPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArm);

	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetupAttachment(RootComponent);
	
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	SpringArm->bUsePawnControlRotation = false;
	CameraComp->bUsePawnControlRotation = false;
	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void AMRTSPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMRTSPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// TODO Move this into the Controllers Move Function
	FVector Velocity = GetMovementComponent()->Velocity;
	if (!Velocity.IsNearlyZero())
	{
		FRotator TargetRotation = Velocity.Rotation();
		// Optionally interpolate for smooth rotation
		FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, 10.0f);
		SetActorRotation(NewRotation);
	}

}