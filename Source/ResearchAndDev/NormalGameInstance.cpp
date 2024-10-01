(// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalGameInstance.h"

void UNormalGameInstance::PrintFromCPP()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *messageForPrinting);
}