// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "main.h"

using namespace std; // Using the "std" namespace, so "cout" can be used instead of "std::cout".

string GetGuessAndPrintBack();

int main()
{
	
	PrintIntro();

	constexpr int NUMBER_OF_TURNS = 5;

	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuessAndPrintBack();
	}

	return 0;
}

void PrintIntro()
{
	constexpr int WORD_LENGT = 5; // constexpr won't change at runtime.
	cout << "WELCOME TO BULLS AND COWS! \n"; // st::endl or "\n" for new line.
	cout << "Can you guess the " << WORD_LENGT << " letter isogram I'm thinking of? \n";
	cout << endl;
	return;
}

string GetGuessAndPrintBack()
{
	// Get a guess from the player.
	cout << "Enter your guess: ";

	string Guess = "";
	// Store input after hitting enter.
	getline(cin, Guess);

	// Repeat the guess back to them.
	cout << "Your guess was: " << Guess;
	cout << endl;
	cout << endl;

	return Guess;
}