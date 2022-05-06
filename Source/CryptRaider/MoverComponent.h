// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMoverComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldMove(bool bMove) { bShouldMove = bMove; }
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Mover|Movement")
	FVector MoveOffset;

	UPROPERTY(EditAnywhere, Category="Mover|Movement")
	float MoveTime{4.f};


	bool bShouldMove{false};

	FVector OriginalLocation;
};
