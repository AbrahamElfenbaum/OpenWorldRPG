// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/Actors/InGameHUD.h"

#pragma region Misc
// Sets default values for this component's properties
UInGameHUD::UInGameHUD()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInGameHUD::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UInGameHUD::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

#pragma endregion

#pragma region Compass Helper Functions
void UInGameHUD::DistanceToPlayer(AActor* Actor, AActor* PlayerRef, double UnitsPerMeter, int32& Distance)
{
	Distance = round(FVector::DistXY(Actor->GetActorLocation(), PlayerRef->GetActorLocation()) / UnitsPerMeter);
}

void UInGameHUD::GetDeltaClockwise(double A, double B, bool isClockwise, double& Delta)
{
	double localA = fmod(A, 360.0);
	double localB = fmod(B, 360.0);
	if (localA == localB)
	{
		Delta = 0.0;
	}
	else
	{
		if (isClockwise == true)
		{
			if (localA > localB)
			{
				Delta = 360.0 - (localA - localB);
			}
			else
			{
				Delta = localB - localA;
			}
		}
		else
		{
			if (localA > localB)
			{
				Delta = localA - localB;
			}
			else
			{
				Delta = 360.0 - (localB - localA);
			}
		}
	}
}

void UInGameHUD::RotationToDegrees(double Rotation, double& Degrees)
{
	fmod(Rotation + 360.0, 360.0);
	if (Rotation < 0.0)
	{
		Degrees = fmod(Rotation + 360.0, 360.0);
	}
	else
	{
		Degrees = Rotation;
	}
}

void UInGameHUD::RotationToTranslation(FRotator A, FRotator B, double MaxWidgetTransform, FVector2D& Translation, bool& isClockwise, bool& isInCompassSight)
{
	double aDegrees;
	double bDegrees;
	double clockwiseDelta;
	double cClockwiseDelta;
	double aAlpha;
	double bAlpha;
	RotationToDegrees(A.Yaw, aDegrees);
	RotationToDegrees(B.Yaw, bDegrees);

	GetDeltaClockwise(aDegrees, bDegrees, true, clockwiseDelta);
	GetDeltaClockwise(aDegrees, bDegrees, false, cClockwiseDelta);

	if (clockwiseDelta > cClockwiseDelta)
	{
		aAlpha = cClockwiseDelta / 90.0;
		if (aAlpha <= 1.0)
		{
			Translation.X = FMath::Lerp(0.0, MaxWidgetTransform, aAlpha) * -1.0;
			Translation.Y = 0.0;
			isClockwise = false;
			isInCompassSight = true;
		}
		else
		{
			Translation.X = 0.0;
			Translation.Y = 0.0;
			isClockwise = false;
			isInCompassSight = false;
		}
	}
	else
	{
		bAlpha = clockwiseDelta / 90.0; 
		if (bAlpha <= 1.0)
		{
			Translation.X = FMath::Lerp(0.0, MaxWidgetTransform, bAlpha);
			Translation.Y = 0.0;
			isClockwise = true;
			isInCompassSight = true;
		}
		else
		{
			Translation.X = 0.0;
			Translation.Y = 0.0;
			isClockwise = true;
			isInCompassSight = false;
		}
	}
}
#pragma endregion



