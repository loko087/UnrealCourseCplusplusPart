// Copyright Headless Chicken Games

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SECTION_03_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	AActor* owner;
	
	UPROPERTY(EditAnywhere)
	float openAngle;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;

	AActor* openActor;

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
