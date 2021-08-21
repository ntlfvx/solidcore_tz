// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfOpeningDoor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASelfOpeningDoor::ASelfOpeningDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Open = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	BoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = BoxComponent;
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Door"));
	Door->SetRelativeLocation(FVector(0.0f, 50.0f, -50.0f));
	Door->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASelfOpeningDoor::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ASelfOpeningDoor::OnOverlapEnd);




}

// Called when the game starts or when spawned
void ASelfOpeningDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelfOpeningDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorRotation = Door->GetRelativeRotation();
	if (Open)
	{
		Door->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f, RotateValue, 0.0f)), 0.01f));
	}
	else
	{
		Door->SetRelativeRotation(FMath::Lerp(FQuat(DoorRotation), FQuat(FRotator(0.0f, 0.0f, 0.0f)), 0.01f));
	}

}

void ASelfOpeningDoor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr)
	{
		FVector PawnLocation = OtherActor->GetActorLocation();
		FVector Direction = GetActorLocation() - PawnLocation;
		Direction = UKismetMathLibrary::LessLess_VectorRotator(Direction, GetActorRotation());

		if (Direction.X > 0.0f)
		{
			RotateValue = 90.0f;
		}
		else
		{
			RotateValue = -90.0f;
		}

		Open = true;
	}
}

void ASelfOpeningDoor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != nullptr && OtherActor != this && OtherComp != nullptr)
	{
		Open = false;
	}
}