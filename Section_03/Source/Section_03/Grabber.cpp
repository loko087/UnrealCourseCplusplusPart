// Copyright Headless Chicken Games

#include "Section_03.h"
#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GRABBER REPORTING!!"));
	
	// ...
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	FVector location;
	FRotator rotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(location,rotation);

	/*UE_LOG(LogTemp, Warning, TEXT("GRABBER REPORTING!! with position %s and rotation %s"),*(location.ToString()),*(rotation.ToString())); */
	FVector lineTraceEnd =  location + rotation.Vector() * reach;
	
	//Draw the line!
	DrawDebugLine(
		GetWorld(),
		location,
		lineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		50.f
		);
	// ...
	//Get the player view-point

}

