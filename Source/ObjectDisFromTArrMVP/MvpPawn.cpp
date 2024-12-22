// Fill out your copyright notice in the Description page of Project Settings.


#include "MvpPawn.h"

// Sets default values
AMvpPawn::AMvpPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMvpPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMvpPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMvpPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

