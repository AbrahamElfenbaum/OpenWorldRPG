// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/ActorComponent.h"
#include "InGameHUD.generated.h"
/*

UCLASS(Blueprintable, BlueprintType)
class UInGameHUD_BPC : public UActorComponent
{
	GENERATED_BODY()

*/

UCLASS(Blueprintable, BlueprintType)
class OPENWORLDRPG_API UInGameHUD : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInGameHUD();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
#pragma region Compass Helper Functions
	UFUNCTION(BlueprintPure, Category = "CompassHelperFunctions")
		void DistanceToPlayer(AActor* Actor, AActor* PlayerRef, double UnitsPerMeter, int32& Distance);
	
	UFUNCTION(BlueprintPure, Category = "CompassHelperFunctions")
		void GetDeltaClockwise(double A, double B, bool isClockwise, double& Delta);

	UFUNCTION(BlueprintPure, Category = "CompassHelperFunctions")
		void RotationToDegrees(double Rotation, double& Degrees);

	UFUNCTION(BlueprintPure, Category = "CompassHelperFunctions")
		void RotationToTranslation(FRotator A, FRotator B, double MaxWidgetTransform, FVector2D& Translation, bool& isClockwise, bool& isInCompassSight);
#pragma endregion

#pragma region Map Helper Functions
	UFUNCTION(BlueprintPure, Category = "MapHelperFunctions")
		void ConvertLocationToPosition(FVector Location, AActor* NWPoint, FVector2D& Position);
	
	UFUNCTION(BlueprintPure, Category = "MapHelperFunctions")
		void GetHeight(AActor* NWPoint, AActor* SEPoint, double& Height);

	UFUNCTION(BlueprintPure, Category = "MapHelperFunctions")
		void GetWidth(AActor* NWPoint, AActor* SEPoint, double& Width);
	
	/*
	UFUNCTION(BlueprintPure, Category = "MapHelperFunctions")
		void GetWidgetSize(UWidget* Widget, FVector2D Resolution, FVector2D& Size);

	UFUNCTION(BlueprintPure, Category = "Map Helper Functions")
		void MapPositionToWorldLocation(FVector2D Position, FVector& Location, double LocalXPercent, double LocalYPercent);
	*/
#pragma endregion


		
};
