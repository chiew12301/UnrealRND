// Copyright Epic Games, Inc. All Rights Reserved.

#include "ResearchAndDevGameMode.h"
#include "ResearchAndDevCharacter.h"
#include "UObject/ConstructorHelpers.h"

AResearchAndDevGameMode::AResearchAndDevGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
