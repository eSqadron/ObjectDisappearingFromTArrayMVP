// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"

#include "MyWidget.h"
#include "Components/TextBlock.h"

void UMyObject::ShowWidget()
{
	if(MyWidget == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("[ShowWidget] Widget is nullptr!"));
		return;
	}

	MyWidget->ObjectNameTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%03d"), NameNumber)));
	MyWidget->AddToViewport();
}
