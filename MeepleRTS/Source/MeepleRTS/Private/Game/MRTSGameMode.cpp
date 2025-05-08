// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/MRTSGameMode.h"
#include "MeepleRTS/Public/Player/MRTSCharacter.h"
#include "MeepleRTS/Public/Player/MRTSController.h"

AMRTSGameMode::AMRTSGameMode()
{
	DefaultPawnClass = AMRTSCharacter::StaticClass();
	PlayerControllerClass = AMRTSController::StaticClass();
}
