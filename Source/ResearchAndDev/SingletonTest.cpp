// Fill out your copyright notice in the Description page of Project Settings.


#include "SingletonTest.h"
#include "Kismet/GameplayStatics.h"
#include "NormalGameInstance.h"
#include "UExampleCustomSingletonClass.h"

// Sets default values
ASingletonTest::ASingletonTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingletonTest::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timerHandler;
	//Calling the funciton 4 secondds delay
	GetWorld()->GetTimerManager().SetTimer(timerHandler, this, &ASingletonTest::GetGameInstanceAndPrintMessage, 4.0f, false);

	UUExampleCustomSingletonClass& templateSingletonInstance = UUExampleCustomSingletonClass::GetInstance();
	templateSingletonInstance.ExampleFunction();
}

// Called every frame
void ASingletonTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASingletonTest::GetGameInstanceAndPrintMessage()
{
	nomralGameInstance = Cast<UNormalGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	nomralGameInstance->messageForPrinting = "Printed From Singleton Test";
	nomralGameInstance->PrintFromCPP();
}

