// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
//#include "OnComponentHit.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ABall::ABall()
{
	//UE_LOG(LogTemp, Warning, TEXT("In Constructor!!!"));

	// Our root component will be a sphere that reacts to physics
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    SphereComponent->InitSphereRadius(10.0f);

    SphereComponent->SetSimulatePhysics(true);
    SphereComponent->SetNotifyRigidBodyCollision(true);

    SphereComponent->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	SphereComponent->OnComponentHit.AddDynamic(this, &ABall::OnHit);


    RootComponent = SphereComponent;

    // Create and position a mesh component so we can see where our sphere is
    SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    SphereVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
    if (SphereVisualAsset.Succeeded())
    {
		//"Setting Sphere as Static Mesh!!!"));
        SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
        //SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
        SphereVisual->SetWorldScale3D(FVector(0.2f));
    }
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tickDelay = FMath::RandRange(tickDelayMin, tickDelayMax);
	locationIncrement = FMath::RandRange(locationIncrementMin, locationIncrementMax);

}

void ABall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	UE_LOG(LogTemp, Warning, TEXT("HIT!!!!"));
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tickCount++;

	if (tickCount%tickDelay == 0) {
		tickCount = 0;
		//UE_LOG(LogTemp, Warning, TEXT("Moving : %f"), tickCount);

		FVector temp = SphereVisual->GetRelativeLocation();

		directionChangeTick++;
		if (directionChangeTick%directionDelay == 0) {
			directionChangeTick = 0;
			direction++;

			if (direction == 4) {
				direction = 0;
			}
		}


		switch(direction) {
			case 0:
				temp += FVector(-locationIncrement, 0, 0);
				break;
			case 1:
				temp += FVector(0, -locationIncrement, 0);
				break;
			case 2:
				temp += FVector(locationIncrement, 0, 0);
				break;
			case 3:
				temp += FVector(0, locationIncrement, 0);
				break;
		}

		//UE_LOG(LogTemp, Warning, TEXT("FVector : %s"), *temp.ToString());
		SphereVisual->SetRelativeLocation(temp);
		tickCount = 0;
	}


}

