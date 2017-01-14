// Fill out your copyright notice in the Description page of Project Settings.

#include "Section_03.h"
#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FString temp = GetOwner()->GetName();
	FString pos = GetOwner()->GetTransform().GetLocation().ToString();
	//FString pos = GetOwner()->GetTransform()
	UE_LOG(LogTemp, Warning, TEXT("Position report for %s is at %s"), *temp,*pos);//, *pos); //This is the same as Debug.Log in unity

}


// Called every frame
void UPositionReport::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

