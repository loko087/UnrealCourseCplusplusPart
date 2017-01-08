#include "FBullCowGame.h"



//Constructor and Destructor
FBullCowGame::FBullCowGame()
{
	Reset();
}

FBullCowGame::~FBullCowGame()
{
}

//Getters 
int32 FBullCowGame::GetCurrentTry() const
{
	return myCurrentTry;
}

int32 FBullCowGame::GetMaxTries() const
{
	return myMaxTries;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}


//Methods
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	myMaxTries = MAX_TRIES;
	myCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString guess)
{
	return false;
}
