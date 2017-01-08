#pragma once
#include <string>
using FString = std::string;
using int32 = int;

class FBullCowGame
{
//Variables
private:
	int32 myCurrentTry;
	int32 myMaxTries;

//Methods
public:
	FBullCowGame();
	~FBullCowGame();
	
	//  Const protects us from modifying the members of the class inside a method
	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString); 

};

