// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTDISFROMTARRMVP_API UMyObject : public UObject
{
	GENERATED_BODY()

public:

	int NameNumber = 0;

	class UMyWidget* MyWidget;

	void ShowWidget();
	
};
