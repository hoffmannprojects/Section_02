#pragma once
#include <string>

class FBullCowGame 
{
public:
	FBullCowGame(); // Constructor.

	int GetMaxTries() const; // const prevents functions from changing variables.
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool IsGuessValid(std::string);

	// TODO Provide a method for counting bulls and cows and increasing try number.

	// Maybe useful in the future.
	//bool WantsToPlayAgain();
	//bool IsGuessCorrect();

private:
	// See constructor for initialization.
	int MyMaxTries;
	int MyCurrentTry;
};