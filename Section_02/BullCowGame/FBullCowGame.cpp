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
int32 FBullCowGame::GetCurrentTry() const{ return myCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return myMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return myHiddenWord.length(); }


bool FBullCowGame::IsGameWon() const{ return false;}

//Methods
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	myMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	myHiddenWord = HIDDEN_WORD;

	myCurrentTry = 1;
	return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (guess.length() != myHiddenWord.length())
		return EWordStatus::Different_Length;
	else 
	{ 
		bool allLower = true;
		for (int32 i = 0; i < guess.length(); i++) 
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

	for (int32 i = 0; i < myHiddenWord.length(); i++)
	{
		for (int32 j = 0; j < myHiddenWord.length(); j++) {
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

	return bullCowCount;
}
