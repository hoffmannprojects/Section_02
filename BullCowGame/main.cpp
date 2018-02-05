// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "main.h"

using namespace std; // Using the "std" namespace, so "cout" can be used instead of "std::cout".

string GetGuess();
void PrintGuess(string Guess);

string Guess = "";

int main()
{	
	PrintIntro();
	PlayGame();
	return 0; // Exit the application.
}

void PrintIntro()
{
	constexpr int WORD_LENGT = 5; // constexpr won't change at runtime.
	cout << "WELCOME TO BULLS AND COWS! \n"; // st::endl or "\n" for new line.
	cout << "Can you guess the " << WORD_LENGT << " letter isogram I'm thinking of? \n";
	cout << endl;
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

string GetGuess()
{
	// Get a guess from the player.
	cout << "Enter your guess: ";

	// Store input after hitting enter.
	getline(cin, Guess);

	return Guess;
}

void PrintGuess(string Guess)
{
	// Repeat the guess back to them.
	cout << "Your guess was: " << Guess;
	cout << endl;
	cout << endl;
}
