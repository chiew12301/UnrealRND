// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTrace.h"
#include "DrawDebugHelpers.h"

// Sets default values
ALineTrace::ALineTrace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Representation"));
	RootComponent = Cube;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (cubeAsset.Succeeded())
	{
		this->Cube->SetStaticMesh(cubeAsset.Object);
		this->Cube->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		this->Cube->SetWorldScale3D(FVector(1.0f));
	}
}

// Called when the game starts or when spawned
void ALineTrace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult outHit;
	FVector start = GetActorLocation();

	FVector forwardVector = GetActorForwardVector();
	FVector end = ((forwardVector * 500.0f) + start);

	FCollisionQueryParams CollisionParams;
	CollisionParams.bTraceComplex = true;
	CollisionParams.AddIgnoredComponent((this->Cube));
	DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 1, 0, 5);
	if (ActorLineTraceSingle(outHit, start, end, ECC_WorldStatic, CollisionParams))
	{
		GEngine->AddOnScreenDebugMessage(-1, 11.0f, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *outHit.GetComponent()->GetName()));
	} 
}

