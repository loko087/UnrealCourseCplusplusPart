#include "FBullCowGame.h"
#include <map>

#define TMap std::map


//Constructor and Destructor
FBullCowGame::FBullCowGame()
{
	Reset();
}

FBullCowGame::~FBullCowGame()
{
}


//Getters 
int32 FBullCowGame::GetCurrentTry() const{ return myCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return myMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const{ return bIsGameWon;}

//Methods
bool FBullCowGame::isIsogram(FString word) const
{
	if (word.length() <= 1) return true;

	TMap<char, bool> letterSeen;
	for (auto letter : word) 
	{
		letter = tolower(letter);
		if (letterSeen[letter]) {
			return false;
		}
		else 
		{
			letterSeen[letter] = true;
		}
	}

	return true;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	myMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;

	bIsGameWon = false;
	myCurrentTry = 1;
	return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!isIsogram(guess)) {
		return EWordStatus::Not_Isogramm;
	}
	else if (guess.length() != myHiddenWord.length())
		return EWordStatus::Different_Length;
	else 
	{ 
		bool allLower = true;
		for (size_t i = 0; i < guess.length(); i++) 
		{
			if (!islower(guess[i])) allLower = false;
		}
		if (!allLower) {
			return EWordStatus::Not_lowercase;
		}
		else {
			return EWordStatus::Ok;
		}
	}

}



/**
*/
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	// TODO  increment turn number, setup a return variable loop through all letters in the guess, compare letters against the hidden word
	myCurrentTry++;
	FBullCowCount bullCowCount;

	for (size_t i = 0; i < myHiddenWord.length(); i++)
	{
		for (size_t j = 0; j < myHiddenWord.length(); j++) {
			if (i == j && guess[j] == myHiddenWord[i])
			{
				bullCowCount.bulls++;
			}
			else  if (guess[j] == myHiddenWord[i])
			{
				bullCowCount.cows++;
			}
		}
	}
	if (bullCowCount.bulls == myHiddenWord.length()) {
		bIsGameWon = true;
	}

	return bullCowCount;
}
