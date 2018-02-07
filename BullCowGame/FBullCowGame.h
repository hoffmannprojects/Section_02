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

	// Maybe useful in the future.
	//bool WantsToPlayAgain();
	//bool IsGuessCorrect();

private:
	// See constructor for initialization.
	int MyMaxTries;
	int MyCurrentTry;
};