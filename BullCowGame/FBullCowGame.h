#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialized to 0.
struct FBullCowCount
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
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool CheckGuessIsValid(FString) const;

	void Reset();
	FBullCowCount SubmitGuess(FString);


private:
	// See constructor for initialization.
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};