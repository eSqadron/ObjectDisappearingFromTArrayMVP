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

	UPROPERTY() // Solution 5 - combination of 1 and 2 (My Widget as UPROPERTY)? - seems to work
	class UMyWidget* MyWidget;

	void ShowWidget();
	
};
