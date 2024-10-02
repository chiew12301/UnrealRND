// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CustomEventManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGenericEvent, int32, Param);

UCLASS()
class RESEARCHANDDEV_API UCustomEventManager : public UObject
{
	GENERATED_BODY()
public:
	UCustomEventManager();

	static UCustomEventManager* GetInstance(UObject* WorldddContectObject);

	UFUNCTION(BlueprintCallable, Category = "Events")
	void AddListener(UObject* listener, FName eventName);

	UFUNCTION(BlueprintCallable, Category = "Events")
	void RemoveListener(UObject* listener, FName eventName);

	UFUNCTION(BlueprintCallable, Category = "Events")
	void AddEvent(FName EventName, int32 Param);

protected:
	TMap<FName, FGenericEvent> eventMap;
};
