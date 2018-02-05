// Logical comments in their own line. // C++ help annotations inline.

#include <iostream> // Includes the standard library "iostream".
#include <string> // Includes standard library for strin operations, eg. >>.

using namespace std; // Using the "std" namespace, so "cout" can be used instead of "std::cout".

int main()
{
	constexpr int WORD_LENGT = 5; // constexpr won't change at runtime.
	
	cout << "WELCOME TO BULLS AND COWS! \n"; // st::endl or "\n" for new line.
	cout << "Can you guess the " << WORD_LENGT << " letter isogram I'm thinking of? \n";
	cout << endl;

	// Get a guess from the player.
	// Store input after hitting enter.
	cout << "Enter your guess: ";
	
	string Guess = "";
	cin >> Guess;

	// Repeat the guess back to them.
	cout << "Your guess was: " << Guess;
	cout << endl;
	cout << endl;


	return 0;
}