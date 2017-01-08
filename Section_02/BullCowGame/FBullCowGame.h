#pragma once
#include <string>

class FBullCowGame
{
//Variables
private:
	int myCurrentTry;
	int myMaxTries;

//Methods
public:
	FBullCowGame();
	~FBullCowGame();
	
	//  Const protects us from modifying the members of the class inside a method
	int GetCurrentTry() const;
	int GetMaxTries() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string); 

};

