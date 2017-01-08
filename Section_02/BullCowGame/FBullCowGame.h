#pragma once
#include <string>
#include <ctype.h>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

//newer syntax
enum class EWordStatus
{
	Ok,
	Not_Isogramm,
	Different_Length,
	Not_lowercase
};

class FBullCowGame
{
//Variables
private:
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;

//Methods
public:
	FBullCowGame();
	~FBullCowGame();
	
	//  Const protects us from modifying the members of the class inside a method
	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;
	int32 GetHiddenWordLength() const;

	void Reset(); 
	FBullCowCount SubmitGuess(FString);

};

