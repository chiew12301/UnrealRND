// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TSingleton.h"
#include "UExampleCustomSingletonClass.generated.h"

UCLASS()
class RESEARCHANDDEV_API UUExampleCustomSingletonClass : public UObject, public TSingleton<UUExampleCustomSingletonClass>
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ExampleFunction();
protected:
	UUExampleCustomSingletonClass() {}
	friend class TSingleton<UUExampleCustomSingletonClass>;
};
