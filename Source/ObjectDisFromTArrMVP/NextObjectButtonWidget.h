// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NextObjectButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTDISFROMTARRMVP_API UNextObjectButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	class UButton* NextObjectButton;
	
};
