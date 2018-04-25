// Copyright Ben Tristem 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Attach Input Component and Bind the Actions
	void InputBinding();

	//Find the Physics Handle (if any)
	void FindPhysicsHandleComponent();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	FHitResult FirstPhysicsObjectHit();

	// How far ahead of the player can we reach in cm
	float Reach = 100.f;
	

	//The grabber has spawned? We don't know
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//
	void Grab();

	//
	void Release();

	void GetReachLine(FVector &begin, FVector &end);

};
