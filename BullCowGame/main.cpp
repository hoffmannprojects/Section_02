/* Console executable, that makes use of the BullCow class.
Acts as the view in a a MVC pattern, and is responsible for all unser interaction.
For game logic see the FBullCowGame class.*/

// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FText Guess = "";

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "       /       /                          \\       \\ \n";
	std::cout << "      |       (                            )       | \n";
	std::cout << "      \\        \\                          /        / \n";
	std::cout << "       \\        ..........................        /\n";
	std::cout << "           ::::                            :::: \n";
	std::cout << "      :::: :::: WELCOME TO BULLS AND COWS! :::: :::: \n"; // st::endl or "\n" for new line.
	std::cout << " :::: :::: :::: .......................... :::: :::: :::: \n";
	std::cout << " :::: :::: ::::     Can you guess the      :::: :::: :::: \n";
	std::cout << " :::: :::: ::::          " << BCGame.GetHiddenWordLength() << " letter          :::: :::: :::: \n";
	std::cout << " :::: :::: ::::  isogram I'm thinking of?  :::: :::: :::: \n";
	std::cout << " :::: :::: :::: .......................... :::: :::: :::: \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		Guess = GetValidGuess();

		// Submit valid guess to the game and receive counts.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();

	return;
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do
	{
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		// Store input after hitting enter.
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessIsValid(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram, a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		// Assume Guess is valid.
		default:
			break;
		}
	} while (Status != EGuessStatus::Ok);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	
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

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "\n YOU WIN! \n\n";
	}
	else
	{
		std::cout << "\n You lost. Better luck next time! \n\n";
	}
	return;
}
