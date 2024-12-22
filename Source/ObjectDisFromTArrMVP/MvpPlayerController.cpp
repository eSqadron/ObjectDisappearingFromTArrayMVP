// Fill out your copyright notice in the Description page of Project Settings.


#include "MvpPlayerController.h"
#include "MvpHUD.h"
#include "NextObjectButtonWidget.h"
#include <Kismet/GameplayStatics.h>
#include "MvpGameModeBase.h"
#include "Components/Button.h"
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
	if (CurrentObject == nullptr)
	{
		CurrentObject = MvpGameMode->GetNextObject();

		if(CurrentObject == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("[ButtonCallback] Couldn't get new object!"));
			return;
		}

		CurrentObject->ShowWidget();
	}
	else
	{
		CurrentObject->MyWidget->RemoveFromViewport();
		CurrentObject = nullptr;
	}
}
