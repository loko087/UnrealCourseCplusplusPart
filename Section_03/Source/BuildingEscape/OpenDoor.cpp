// Copyright Ben Tristem 2016.

#include "OpenDoor.h"
#include "BuildingEscape.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
//	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	//Super::BeginPlay();

	Owner = GetOwner();
	if (!PressurePlate) 
		UE_LOG(LogTemp, Error, TEXT("%s missing Pressure Plate"), *GetOwner()->GetName());


}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	// If the ActorThatOpens is in the volume
	if (GetObjectsMassInPlace() > 50.0f)
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	// Check if it's time to close the door
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
}

float UOpenDoor::GetObjectsMassInPlace()
{
	if (!PressurePlate) return;
	
	float totalMassInPlace = 0.f;

	TArray<AActor*> overlappingActors;

	PressurePlate->GetOverlappingActors(overlappingActors);

	for (auto& overlapping: overlappingActors) {
		totalMassInPlace += overlapping->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp,Warning,TEXT("%s is on the plate"),*overlapping->GetName())
	}

	return totalMassInPlace;
}
