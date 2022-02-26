// Fill out your copyright notice in the Description page of Project Settings.


#include "TestSquare.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ATestSquare::ATestSquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (CylinderAsset.Succeeded())
    {
        Mesh->SetStaticMesh(CylinderAsset.Object);
        Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        Mesh->SetWorldScale3D(FVector(1.f));
	}

}

// Called when the game starts or when spawned
void ATestSquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

