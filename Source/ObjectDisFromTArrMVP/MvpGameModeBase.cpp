// Fill out your copyright notice in the Description page of Project Settings.


#include "MvpGameModeBase.h"

#include "MyObject.h"

AMvpGameModeBase::AMvpGameModeBase()
{
	for (int i = 0; i < 10; i++)
	{
		MyObjects.Add(CreateNewObject());
	}
}

UMyObject* AMvpGameModeBase::GetNextObject()
{
	return MyObjects.Pop();
}

UMyObject* AMvpGameModeBase::CreateNewObject()
{
	auto _newObject = NewObject<UMyObject>();

	return _newObject;
}
