#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame 
{
public:
	FBullCowGame(); // Constructor.

	int32 GetMaxTries() const; // const prevents functions from changing variables.
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool IsGuessValid(FString);

	// TODO Provide a method for counting bulls and cows and increasing try number.

	// Maybe useful in the future.
	//bool WantsToPlayAgain();
	//bool IsGuessCorrect();

private:
	// See constructor for initialization.
	int32 MyMaxTries;
	int32 MyCurrentTry;
};