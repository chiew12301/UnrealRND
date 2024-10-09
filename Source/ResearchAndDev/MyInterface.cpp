// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInterface.h"

void IMyInterface::SaySomething()
{
	UE_LOG(LogTemp, Warning, TEXT("Hi %s"), *name);
}

void IMyInterface::ReactToTriggerBegin()
{
	UE_LOG(LogTemp, Warning, TEXT("Hi %s"), *name);
}

void IMyInterface::ReactToTriggerEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("Hi %s"), *name);
}
