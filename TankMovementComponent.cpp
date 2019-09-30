// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if (!LeftTrackToSet || !RightTrackToSet) {return;}
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto AIForwardIntention = MoveVelocity.GetSafeNormal();

    auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

    auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
    IntendTurnRight =(RightThrow);

    IntendMoveForward(ForwardThrow);
}

void UTankMovementComponent::IntendMoveFOrward(float Throw)
{
    // auto Name = GetName();
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

 {
    // auto Name = GetName();
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}