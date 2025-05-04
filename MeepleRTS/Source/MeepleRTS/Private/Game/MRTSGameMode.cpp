// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/MRTSGameMode.h"
#include "MeepleRTS/Public/Player/MRTSPawn.h"
#include "MeepleRTS/Public/Player/MRTSController.h"

AMRTSGameMode::AMRTSGameMode()
{
	DefaultPawnClass = AMRTSPawn::StaticClass();
	PlayerControllerClass = AMRTSController::StaticClass();
}
