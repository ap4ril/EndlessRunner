#include "RunAnimInstance.h"

#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void URunAnimInstance::NativeInitializeAnimation()
{
	if (pawn == nullptr)
	{
		pawn = TryGetPawnOwner();
	}

	if (IsValid(pawn))
	{
		MovementComponent = pawn->GetMovementComponent();
	}
}

void URunAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (pawn && MovementComponent)
	{
		bIsInAir = MovementComponent->IsFalling();

		Speed = pawn->GetVelocity().Size();
	}
}
