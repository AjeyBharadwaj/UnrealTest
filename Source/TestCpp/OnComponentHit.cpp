// Harrison McGuire
// UE4 Version 4.20.2
// https://github.com/Harrison1/unrealcpp
// https://severallevels.io
// https://harrisonmcguire.com

#include "OnComponentHit.h"
#include "Components/BoxComponent.h"

static int GFNumber = 0;

// Sets default values
AOnComponentHit::AOnComponentHit()
{
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// add Cylinder to root
    Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(FName(FString::Printf(TEXT("Cylinder-%d"), ++GFNumber)));
    RootComponent = Cylinder;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (CylinderAsset.Succeeded())
    {
        Cylinder->SetStaticMesh(CylinderAsset.Object);
        Cylinder->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        Cylinder->SetWorldScale3D(FVector(1.f));
	}

	Cylinder->SetSimulatePhysics(true);

	Cylinder->SetNotifyRigidBodyCollision(true);
	Cylinder->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	Cylinder->OnComponentHit.AddDynamic(this, &AOnComponentHit::OnCompHit);

	/*
	// Use a sphere as a simple collision representation
	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &AOnComponentHit::OnCompHit);

	// Set as root component
	RootComponent = MyComp;
	*/
}

void AOnComponentHit::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s Hit %s"), *Cylinder->GetName(), *OtherActor->GetName()));//*OtherActor->GetName()));
		FString other = OtherActor->GetName();
		//if (other.Find("harac") != -1) Destroy();
	}
}