// Fill out your copyright notice in the Description page of Project Settings.


#include "MvpGameModeBase.h"

#include "MyObject.h"

AMvpGameModeBase::AMvpGameModeBase()
{
	// Solution 3 - create all objects separately here

	for (int i = 0; i < 10; i++)
	{
		MyObjects.Add(CreateNewObject(i));
	}
}

UMyObject* AMvpGameModeBase::GetNextObject()
{
	return MyObjects.Pop();
}

UMyObject* AMvpGameModeBase::CreateNewObject(int number)
{
	auto _newObject = NewObject<UMyObject>();

	_newObject->NameNumber = number;

	// Solution 2 - Add object and widget to root - This particular line was partial success
	_newObject->AddToRoot();
	// Solution 5 - combination of 1 and 2 (MyObject added to root, My Widget as UPROPERTY)? - seems to work

	// _newObject->SetFlags(RF_MarkAsRootSet); // Solution 4 - Set flag to RF_MarkAsRootSet

	return _newObject;
}
