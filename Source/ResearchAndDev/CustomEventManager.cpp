// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomEventManager.h"
#include "Kismet/GameplayStatics.h"

UCustomEventManager::UCustomEventManager()
{

}

UCustomEventManager* UCustomEventManager::GetInstance(UObject* WorldddContectObject)
{
	static UCustomEventManager* instance = nullptr;

	if (instance == nullptr)
	{
		instance = NewObject<UCustomEventManager>();
		instance->AddToRoot();
	}

	return instance;
}

template <typename T>
void UCustomEventManager::AddListener(T* listener, FName eventName, void(T::* Func)(int32))
{
	if (!eventMap.Contains(eventName))
	{
		eventMap.Add(eventName);
	}

	FGenericEvent& event = eventMap[eventName];
	event.AddDynamic(listener, Func);
}

template <typename T>
void UCustomEventManager::RemoveListener(T* listener, FName eventName, void(T::* Func)(int32))
{
	if (!eventMap.Contains(eventName))
	{
		FGenericEvent& event = eventMap[eventName];
		event.RemoveDynamic(listener, Func);
	}
}

void UCustomEventManager::AddEvent(FName EventName, int32 Param)
{
	if (!eventMap.Contains(EventName))
	{
		UE_LOG(LogTemp, Warning, TEXT("Event %s not found!"), *EventName.ToString());
		return;
	}

	FGenericEvent& event = eventMap[EventName];
	event.Broadcast(Param);
}