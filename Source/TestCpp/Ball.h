// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class TESTCPP_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	USphereComponent* SphereComponent;
	UStaticMeshComponent* SphereVisual;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	int tickDelayMin = 1;
	int tickDelayMax = 5;
	int tickDelay = 1;

	int tickCount = 0;
	int direction = 0;
	int directionDelay = 50;
	int directionChangeTick = 0;

	int locationIncrement = 10;	
	int locationIncrementMin = 1;	
	int locationIncrementMax = 10;

};
