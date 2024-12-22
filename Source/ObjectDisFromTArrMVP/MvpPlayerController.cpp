// Fill out your copyright notice in the Description page of Project Settings.


#include "MvpPlayerController.h"
#include "MvpHUD.h"
#include "NextObjectButtonWidget.h"
#include <Kismet/GameplayStatics.h>
#include "MvpGameModeBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MyWidget.h"
#include "MyObject.h"

void AMvpPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

	MvpHUD = Cast<AMvpHUD>(GetHUD());

	MvpGameMode = Cast<AMvpGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));


	MvpHUD->NextObjectButtonWidget = CreateWidget<UNextObjectButtonWidget>(this, MvpHUD->NextObjectButtonWidgetClass);

	MvpHUD->NextObjectButtonWidget->NextObjectButton->OnClicked.AddDynamic(this, &AMvpPlayerController::ButtonCallback);

	MvpHUD->NextObjectButtonWidget->AddToViewport();

	for (auto obj : MvpGameMode->MyObjects)
	{
		obj->MyWidget = CreateWidget<UMyWidget>(this, MvpHUD->MyWidgetClass);
	}

}

void AMvpPlayerController::ButtonCallback()
{
	static int counter = 0;

	if (CurrentObject == nullptr)
	{
		CurrentObject = MvpGameMode->GetNextObject();
		CurrentObject->MyWidget->ObjectNameTextBlock->SetText(FText::FromString(FString::Printf(TEXT("%03d"), counter++)));
		CurrentObject->MyWidget->AddToViewport();
	}
	else
	{
		CurrentObject->MyWidget->RemoveFromViewport();
		CurrentObject = nullptr;
	}
}
