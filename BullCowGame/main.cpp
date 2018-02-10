/* Console executable, that makes use of the BullCow class.
Acts as the view in a a MVC pattern, and is responsible for all unser interaction.
For game logic see the FBullCowGame class.*/

// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FText GetValidGuess();
FText Guess = "";
bool AskToPlayAgain();

// Instantiate a new game.
FBullCowGame BCGame;

int main()
{	
	PrintIntro();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());

	// Exit the application.
	return 0; 
}

void PrintIntro()
{
	std::cout << "WELCOME TO BULLS AND COWS! \n"; // st::endl or "\n" for new line.
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// TODO Change from "for" to "while" loop once validating tries.
	for (int32 count = 1; count <= MaxTries; count++)
	{
		Guess = GetValidGuess();

		// Submit valid guess to the game and receive counts.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO Summarise game.
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do
	{
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		// Store input after hitting enter.
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessIsValid(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram, a word without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	}
	while (Status != EGuessStatus::Ok);
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;

	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
