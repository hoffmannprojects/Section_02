/* Console executable, that makes use of the BullCow class.
Acts as the view in a a MVC pattern, and is responsible for all unser interaction.
For game logic see the FBullCowGame class.*/

// Logical comments in their own line. // C++ help annotations inline.

#pragma once

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for string operations, eg. >>.
#include "FBullCowGame.h"

// To make syntax Unreal friendly.
using FText = std::string;
using int32 = int;

// Function prototypes, because we're not in a class and have no header file.
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FText Guess = "";

// Instantiate a new game, which we use across plays.
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
	std::cout << "      :::: :::: WELCOME TO BULLS AND COWS! :::: :::: \n";
	std::cout << " :::: :::: :::: .......................... :::: :::: :::: \n";
	std::cout << " :::: :::: ::::     Can you guess the      :::: :::: :::: \n";
	std::cout << " :::: :::: ::::          " << BCGame.GetHiddenWordLength() << " letter          :::: :::: :::: \n";
	std::cout << " :::: :::: ::::  isogram I'm thinking of?  :::: :::: :::: \n";
	std::cout << " :::: :::: :::: .......................... :::: :::: :::: \n";
	std::cout << std::endl;
	return;
}

// Plays a single game to completion.
void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		Guess = GetValidGuess();

		FBullsCowsCount BullsCowsCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullsCowsCount.Bulls;
		std::cout << ", Cows = " << BullsCowsCount.Cows << "\n\n";
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
