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

	// Here solution 1 was breaking, MyObjects array was nulled after leaving the constructor.
	for (auto obj : MvpGameMode->MyObjects)
	{
		obj->MyWidget = CreateWidget<UMyWidget>(this, MvpHUD->MyWidgetClass);
		//obj->MyWidget->AddToRoot(); // Solution 2 - Add object and widget to root - complete disaster, causes a lot of crashes
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
		CurrentObject->RemoveFromRoot(); // Solution 5 - combination of 1 and 2? - seems to work
		CurrentObject = nullptr;
	}
}
