// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereCpp.h"


// Sets default values
ASphereCpp::ASphereCpp(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	class USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
    RootComponent = SphereComponent;

	Sphere = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if(StaticMesh.Succeeded())
		Sphere->SetStaticMesh(StaticMesh.Object);
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/M_Sphere.M_Sphere'"));
	if (Material.Succeeded())
		Sphere->SetMaterial(0, Material.Object);

	Sphere->SetupAttachment(RootComponent);
}

// Called every frame
void ASphereCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float realtimeSeconds = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	float zLoc = (FMath::Cos(realtimeSeconds*2)*100);
	Sphere->SetRelativeLocation(FVector(0,0,zLoc));
}


// Called when the game starts or when spawned
void ASphereCpp::BeginPlay()
{
	Super::BeginPlay();
	
}
