#pragma once

#include "GameFramework/Character.h"
#include "BlerpCharacter.generated.h"

UCLASS()
class ABlerpCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void HandleJumpInput();

	UFUNCTION(BlueprintCallable)
	void HandleMoveForwardInput(float Value);

	UFUNCTION(BlueprintCallable)
	void HandleMoveRightInput(float Value);

	UFUNCTION(BlueprintCallable)
	void HandleLookRightInput(float Value);

	UFUNCTION(BlueprintCallable)
	void HandleLookUpInput(float Value);

	UPROPERTY(EditDefaultsOnly, Category = "Jumping")
	float TraceLength = -100.f;
};