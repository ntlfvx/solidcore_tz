// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tz_Solidcore_v01GameMode.h"
#include "Tz_Solidcore_v01HUD.h"
#include "Tz_Solidcore_v01Character.h"
#include "UObject/ConstructorHelpers.h"

ATz_Solidcore_v01GameMode::ATz_Solidcore_v01GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATz_Solidcore_v01HUD::StaticClass();
}
