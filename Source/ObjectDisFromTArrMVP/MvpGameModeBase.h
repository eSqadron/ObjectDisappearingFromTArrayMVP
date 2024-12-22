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

	//UPROPERTY() // Solution 1 - Setting object array as UPROPERTY. This however caused whole array to be nulled after leaving the constructor.
	TArray<class UMyObject*> MyObjects;

	class UMyObject* GetNextObject();

private:
	class UMyObject* CreateNewObject(int number);

	// UPROPERTY() // Solution 3 - all objects separately with UPROPERTY(). There was no observable difference between this base behaviour
	// class UMyObject* object1 = nullptr;
	// UPROPERTY()
	// class UMyObject* object2 = nullptr;
	// etc. 
};
