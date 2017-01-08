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
int FBullCowGame::GetCurrentTry() const
{
	return myCurrentTry;
}

int FBullCowGame::GetMaxTries() const
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
	constexpr int MAX_TRIES = 5;
	myMaxTries = MAX_TRIES;
	myCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
