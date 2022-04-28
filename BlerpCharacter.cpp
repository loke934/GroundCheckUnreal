#include "BlerpCharacter.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

void ABlerpCharacter::HandleJumpInput()
{
	FHitResult Hit;
	FVector StartPos = GetActorLocation();
	FVector EndPos = StartPos + (GetActorUpVector() * TraceLength);
	bool CanJump = GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos, FCollisionObjectQueryParams::AllStaticObjects, Hit.bBlockingHit);

	if (CanJump)
	{
		Jump();
	}
}

void ABlerpCharacter::HandleMoveForwardInput(float Value)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()) * Value);
}

void ABlerpCharacter::HandleMoveRightInput(float Value)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()) * Value);
}

void ABlerpCharacter::HandleLookRightInput(float Value)
{
	AddControllerYawInput(Value);
}

void ABlerpCharacter::HandleLookUpInput(float Value)
{
	AddControllerPitchInput(Value);
}