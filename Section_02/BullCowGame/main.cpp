/* This is the consol executable, it follows the MVC pattern

*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();
FBullCowGame playerGame;
void printBullsAndCows(FBullCowCount, FText);

int32 main() 
{
	do{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;

}

void PrintIntro() {

	constexpr int32  WORD_LENGTH = 5; //This is how you declare a constant expression, meaning something we won't change during compile time
	std::cout << "Welcome to the Bulls and Cows game\n";
	std::cout << "Can you guess the " << playerGame.GetHiddenWordLength() << " letter isogram am thinking of?\n";
	std::cout << std::endl;

}

FText GetGuess() 
{
	//get the guess from the player

	FText guess = "";

	//std::cin >> guess;
	std::cout << "Enter your guess: ";
	std::getline(std::cin, guess);
	//std::cout << std::endl;

	return guess;
}

void PlayGame()
{

	FText guess = "";
	playerGame.Reset();
	//constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 i = 0; i <= playerGame.GetMaxTries() && !playerGame.IsGameWon(); i++)
	{
		guess = GetGuess();
		EWordStatus status = playerGame.CheckGuessValidity(guess);
		if( status == EWordStatus::Ok){
		FBullCowCount bullCowCount = playerGame.SubmitGuess(guess);
		printBullsAndCows(bullCowCount, guess);
		}
		else {
			switch (status) {
			case(EWordStatus::Different_Length):
				std::cout << "Not the same lenght, please enter a "<< playerGame.GetHiddenWordLength() <<" length word" << std::endl;
				break;
			case(EWordStatus::Not_Isogramm) :
				std::cout << "Not an isogramm" << std::endl;
				break;
			case(EWordStatus::Not_lowercase) :
				std::cout << "Not all lowercase, please try again" << std::endl;
				break;
			}
			i--;
		}
	}
	if (playerGame.IsGameWon()) std::cout << "Congratulations! the word is " << guess << std::endl; else std::cout << "You failed to guess the word" << std::endl;

	return;

}

void printBullsAndCows(FBullCowCount bullCowCount, FText guess) {
	std::cout << "Your Guess was: " << guess << std::endl;
	std::cout << "Bulls = " << bullCowCount.bulls;
	std::cout << ".Cows = " << bullCowCount.cows << std::endl;
	return;
}

bool AskToPlayAgain()
{
	FText response = "";
	bool continueGame = false;
	std::cout << "Do you want to play again?";
	std::getline(std::cin, response);
	
	if (response[0] == 'y' || response[0] == 'Y')
		continueGame = true;

	//std::cout << "is it Y?" << (response[0] == 'y');
	//std::cout << std::endl;

	return continueGame;
}

