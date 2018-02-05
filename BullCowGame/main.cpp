// Includes the standard library "iostream".
#include <iostream>

// Using the "std" namespace, so "cout" can be used instead of "std::cout".
using namespace std;

int main()
{
	// constexpr won't change at runtime.
	constexpr int WORD_LENGT = 5;

	// st::endl or "\n" for new line.
	cout << "Welcome to Bulls and Cows. \n";
	cout << "Can you guess the " << WORD_LENGT << " letter isogram I'm thinking of? \n";
	cout << endl;
	return 0;
}