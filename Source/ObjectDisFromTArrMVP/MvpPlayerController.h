// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MvpPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTDISFROMTARRMVP_API AMvpPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	class AMvpHUD* MvpHUD;

	class AMvpGameModeBase* MvpGameMode;

	UFUNCTION()
	void ButtonCallback();

private:
	class UMyObject* CurrentObject = nullptr;
};
