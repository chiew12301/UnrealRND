// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RESEARCHANDDEV_API IMyInterface
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Trigger Reaction")
	bool ReactToTrigger() const;

	virtual void SaySomething();
	virtual void ReactToTriggerBegin();
	virtual void ReactToTriggerEnd();

	FString name;
};
