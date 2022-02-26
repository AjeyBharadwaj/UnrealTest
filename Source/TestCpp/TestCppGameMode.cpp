// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestCppGameMode.h"
#include "TestCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestCppGameMode::ATestCppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
