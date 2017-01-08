#pragma once
#include <string>

class FBullCowGame
{
//Variables
public:
	int getCurrentTry;

private:
	int myCurrentTry;
	int myMaxTries;

//Methods
public:
	FBullCowGame();
	~FBullCowGame();
	
	void Reset();
	int GetMaxTries();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); 
	

private:

};

