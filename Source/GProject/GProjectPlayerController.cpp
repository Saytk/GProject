// Copyright Epic Games, Inc. All Rights Reserved.

#include "GProjectPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "GProjectCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AGProjectPlayerController::AGProjectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

}


//
//// Triggered every frame when the input is held down
//void AGProjectPlayerController::OnSetDestinationTriggered()
//{
//	// We flag that the input is being pressed
//	FollowTime += GetWorld()->GetDeltaSeconds();
//	
//	// We look for the location in the world where the player has pressed the input
//	FHitResult Hit;
//	bool bHitSuccessful = false;
//	if (bIsTouch)
//	{
//		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
//	}
//	else
//	{
//		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
//	}
//
//	// If we hit a surface, cache the location
//	if (bHitSuccessful)
//	{
//		CachedDestination = Hit.Location;
//	}
//	
//	// Move towards mouse pointer or touch
//	APawn* ControlledPawn = GetPawn();
//	if (ControlledPawn != nullptr)
//	{
//		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
//		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
//	}
//}
//
//void AGProjectPlayerController::OnSetDestinationReleased()
//{
//	// If it was a short press
//	if (FollowTime <= ShortPressThreshold)
//	{
//		// We move there and spawn some particles
//		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
//		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
//	}
//
//	FollowTime = 0.f;
//}
//
//// Triggered every frame when the input is held down
//void AGProjectPlayerController::OnTouchTriggered()
//{
//	bIsTouch = true;
//	OnSetDestinationTriggered();
//}
//
//void AGProjectPlayerController::OnTouchReleased()
//{
//	bIsTouch = false;
//	OnSetDestinationReleased();
//}
