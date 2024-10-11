// Fill out your copyright notice in the Description page of Project Settings.


#include "AddMeshFromFile.h"

// Sets default values
AAddMeshFromFile::AAddMeshFromFile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    UStaticMeshComponent* Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_SpawnedCylinder"));
    RootComponent = Cylinder;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));

    if (CylinderAsset.Succeeded())
    {
        Cylinder->SetStaticMesh(CylinderAsset.Object);
        Cylinder->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        Cylinder->SetWorldScale3D(FVector(1.f));
    }
}