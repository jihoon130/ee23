// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
FTimerHandle TimerHandle;
int a = 0;
// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{

	Super::BeginPlay();
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	if(!GetWorldTimerManager().IsTimerActive(TimerHandle))
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATile::RepeatingFunction, 1.0f, true, 2.0f);

	if(a==1)
	SetActorTransform(FTransform(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 1)));

	if (GetActorLocation().Z >= 2000.0f)
		Destroy(this);
	Super::Tick(DeltaTime);
}

void ATile::RepeatingFunction()
{
	a = 1;
}

