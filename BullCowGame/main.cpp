// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "main.h"

std::string GetGuess();
void PrintGuess(std::string Guess);
bool AskToPlayAgain();

std::string Guess = "";

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
	constexpr int NUMBER_OF_TURNS = 5;

	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		Guess = GetGuess();
		PrintGuess(Guess);
	}
}

std::string GetGuess()
{
	std::cout << "Enter your guess: ";

	// Store input after hitting enter.
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
