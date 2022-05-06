// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

#include "MoverComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UTriggerComponent::GetAcceptableActor(AActor*& AcceptableActor) const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (const auto Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag) && !Actor->ActorHasTag(UnAcceptableActorTag))
		{
			AcceptableActor = Actor;
			return true;
		}
	}
	return false;
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* AcceptableActor;
	if (GetAcceptableActor(AcceptableActor))
	{
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(AcceptableActor->GetRootComponent());
		if (Component != nullptr)
		{
			Component->SetSimulatePhysics(false);
			Component->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		}
		Mover->SetShouldMove(true);
	}
	else
	{
		Mover->SetShouldMove(false);
	}
}

void UTriggerComponent::SetMover(UMoverComponent* NewMover)
{
	Mover = NewMover;
}
