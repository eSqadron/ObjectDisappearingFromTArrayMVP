// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "NextObjectButtonWidget.h"
#include "MyWidget.h"

#include "MvpHUD.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTDISFROMTARRMVP_API AMvpHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UNextObjectButtonWidget> NextObjectButtonWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyWidget> MyWidgetClass;


	class UNextObjectButtonWidget* NextObjectButtonWidget;
	
};
