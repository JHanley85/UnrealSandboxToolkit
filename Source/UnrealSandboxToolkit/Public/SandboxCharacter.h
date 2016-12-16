// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "SandboxCharacter.generated.h"



UENUM(BlueprintType)
enum class PlayerView : uint8 {
	TOP_DOWN = 0		UMETA(DisplayName = "Top Down"),
	THIRD_PERSON = 1	UMETA(DisplayName = "Third Person"),
	FIRST_PERSON = 2	UMETA(DisplayName = "First Person")
};

UCLASS()
class UNREALSANDBOXTOOLKIT_API ASandboxCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASandboxCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	void initTopDownView();

	void initThirdPersonView();

	PlayerView GetSandboxPlayerView();

	void SetSandboxPlayerView(PlayerView SandboxView);

	UPROPERTY(EditAnywhere, Category = "UnrealSandbox")
	PlayerView InitialView = PlayerView::TOP_DOWN;

private:
	PlayerView view;

protected:
	void ZoomIn();

	void ZoomOut();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	virtual void AddControllerYawInput(float Val) override;

	virtual void AddControllerPitchInput(float Val) override;
	
};