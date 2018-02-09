#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialized to 0.
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 
{
public:
	FBullCowGame(); // Constructor.

	int32 GetMaxTries() const; // const prevents functions from changing variables.
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool IsGuessValid(FString);

	BullCowCount SubmitGuess(FString);

	// Maybe useful in the future.
	//bool WantsToPlayAgain();
	//bool IsGuessCorrect();

private:
	// See constructor for initialization.
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};