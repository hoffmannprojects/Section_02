// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "main.h"
#include "FBullCowGame.h"

std::string GetGuess();
std::string Guess = "";
void PrintGuess(std::string Guess);
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
	constexpr int WORD_LENGT = 5; // constexpr won't change at runtime.
	std::cout << "WELCOME TO BULLS AND COWS! \n"; // st::endl or "\n" for new line.
	std::cout << "Can you guess the " << WORD_LENGT << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();

	// TODO Change from "for" to "while" loop once validating tries.
	for (int count = 1; count <= MaxTries; count++)
	{
		Guess = GetGuess();

		// Submit valid guess to the game.
		// Print number of bulls and cows.

		PrintGuess(Guess);
	}

	// TODO Summarise game.
}

std::string GetGuess()
{
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	// Store input after hitting enter.
	// TODO make check for validity.
	getline(std::cin, Guess);

	return Guess;
}

void PrintGuess(std::string Guess)
{
	std::cout << "Your guess was: " << Guess;
	std::cout << std::endl;
	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	
	std::string Response = "";
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
