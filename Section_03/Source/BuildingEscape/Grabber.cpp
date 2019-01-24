// Copyright Ben Tristem 2016.
#include "Grabber.h"
#include "BuildingEscape.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandleComponent();

	InputBinding();
}

void UGrabber::InputBinding()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		/// Bind the Input Axis
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName());
	}
}

void UGrabber::FindPhysicsHandleComponent()
{
	/// Look for attached physics handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName());
	}
}

// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	// See what what we hit

	if (!PhysicsHandle) return;

	FVector LineTraceEnd;
	FVector LineBegin;
	UGrabber::GetReachLine(OUT LineBegin , OUT LineTraceEnd);
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}

}

FHitResult UGrabber::FirstPhysicsObjectHit()
{
	FVector LineTraceEnd;
	FVector PlayerViewPointLocation;

	UGrabber::GetReachLine(OUT PlayerViewPointLocation, OUT LineTraceEnd);
	// Draw a red trace in the world to visualise
	UKismetSystemLibrary::DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		0.f,
		10.f
	);

	FCollisionQueryParams traceParameters(FName(TEXT("")), false, GetOwner());

	// Ray-cast out to reach distance
	FHitResult hit;

	if (GetWorld()->LineTraceSingleByObjectType(
		OUT hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		traceParameters
	)) {
		FString hitName = hit.Actor->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *hitName);

	}
	return hit;

}

void UGrabber::Grab() {
	if (!PhysicsHandle) return;

	UE_LOG(LogTemp, Warning, TEXT("Grab Pressed"));

	auto hitResult = FirstPhysicsObjectHit();
	auto componentToGrab = hitResult.GetComponent();
	auto actorHit = hitResult.GetActor();

	if(actorHit)
	{
		PhysicsHandle->GrabComponent(
			componentToGrab, 
			NAME_None, 
			actorHit->GetActorLocation(), 
			true
		);
	}
}

void UGrabber::Release() {
	if (!PhysicsHandle) return;

	UE_LOG(LogTemp, Warning, TEXT("Grab Released"));
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->ReleaseComponent();
	}
}

void UGrabber::GetReachLine(FVector &begin, FVector &end) 
{
	// Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	begin = PlayerViewPointLocation;
	end = LineTraceEnd;

}