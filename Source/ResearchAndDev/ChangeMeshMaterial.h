// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangeMeshMaterial.generated.h"

UCLASS()
class RESEARCHANDDEV_API AChangeMeshMaterial : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChangeMeshMaterial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* myMesh;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* onMaterial;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* offMaterial;

	UPROPERTY()
	class UBoxComponent* myBoxComponent;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
