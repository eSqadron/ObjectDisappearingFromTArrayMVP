// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MvpGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTDISFROMTARRMVP_API AMvpGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMvpGameModeBase();

	TArray<class UMyObject*> MyObjects;

	class UMyObject* GetNextObject();

private:
	class UMyObject* CreateNewObject();
};
