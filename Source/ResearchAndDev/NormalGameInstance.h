// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NormalGameInstance.generated.h"

UCLASS()
class RESEARCHANDDEV_API UNormalGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	FString messageForPrinting;

	UFUNCTION(BlueprintCallable)
	void PrintFromCPP();
};
