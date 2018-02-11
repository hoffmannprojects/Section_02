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

enum class EGuessStatus
{
	Invalid_Status,
	Ok, 
	Not_Isogram, 
	Wrong_Length, 
	Not_Lowercase
};

class FBullCowGame 
{
public:
	FBullCowGame(); // Constructor.

	int32 GetMaxTries() const; // const prevents functions from changing variables.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessIsValid(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);


private:
	// See constructor for initialization.
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
};