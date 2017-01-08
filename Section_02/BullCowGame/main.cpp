#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();
void PlayGame();
bool AskToPlayAgain();

int main() 
{
	do{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;

}

void PrintIntro() {

	constexpr int  WORD_LENGTH = 5; //This is how you declare a constant expression, meaning something we won't change during compile time
									//Macros replacement??? 

	cout << "Welcome to the Bulls and Cows game\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram am thinking of?\n";
	cout << endl;

}

string GetGuess() 
{
	//get the guess from the player

	string guess = "";

	//cin >> guess;
	cout << "Enter your guess: ";
	getline(cin, guess);
	//cout << endl;

	return guess;
}

void PlayGame()
{
	string guess = "";
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i <= NUMBER_OF_TURNS; i++)
	{
		guess = GetGuess();
		cout << "Your Guess was: " << guess << endl;
		cout << endl;
	}
}

bool AskToPlayAgain()
{
	string response = "";
	bool continueGame = false;
	cout << "Do you want to play again?";
	getline(cin, response);
	
	if (response[0] == 'y' || response[0] == 'Y')
		continueGame = true;

	//cout << "is it Y?" << (response[0] == 'y');
	//cout << endl;

	return continueGame;
}

