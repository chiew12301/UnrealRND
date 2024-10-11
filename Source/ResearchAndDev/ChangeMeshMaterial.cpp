// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeMeshMaterial.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"


// Sets default values
AChangeMeshMaterial::AChangeMeshMaterial()
{
	this->myMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	this->myMesh->SetupAttachment(RootComponent);
	RootComponent = this->myMesh;

	this->myBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	this->myBoxComponent->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	this->myBoxComponent->SetCollisionProfileName("Trigger");
	this->myBoxComponent->SetupAttachment(RootComponent);

	this->onMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	this->offMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));
	this->myBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AChangeMeshMaterial::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AChangeMeshMaterial::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::White, true, -1, 0, 10);

	this->myMesh->SetMaterial(0, this->offMaterial);
}

void AChangeMeshMaterial::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		this->myMesh->SetMaterial(0, this->onMaterial);
	}
}