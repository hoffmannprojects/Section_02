// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.
#include "main.h"

using namespace std; // Using the "std" namespace, so "cout" can be used instead of "std::cout".

string GetGuess();
void PrintGuess(string Guess);
bool AskToPlayAgain();

string Guess = "";

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
	cout << "Enter your guess: ";

	// Store input after hitting enter.
	getline(cin, Guess);

	return Guess;
}

void PrintGuess(string Guess)
{
	cout << "Your guess was: " << Guess;
	cout << endl;
	cout << endl;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	
	string Response = "";
	getline(cin, Response);
	cout << endl;

	if ((Response[0] == 'y') || (Response[0] == 'Y'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
