// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController can't find a tank"));
    }
    else 
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player %s"), *(ControlledTank->GetName()));
    }
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

    auto ControlledTank = Cast<ATank>(GetPawn());

    if (PlayerTank)
    {
        // Aim towards the player
        MoveToActor(PlayerTank, AcceptanceRadius, );
        // GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

        // Fire if ready
        ControlledTank->Fire();
    }

}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

// ATank* ATankAIController::GetPlayerTank() const
// {
//     auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//     if (!PlayerPawn) { return nullptr; }
//     return Cast<ATank>(PlayerPawn);
// }