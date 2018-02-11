/* This class is responsible for handling all game logic.
For view code (handling user interaction), see main.cpp.
The game is a simple guess the word game based on Mastermind.*/

#pragma once
#include <string>

// To make syntax Unreal friendly.
using FString = std::string;
using int32 = int;

struct FBullsCowsCount
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
	FBullsCowsCount SubmitValidGuess(FString);


private:
	// See constructors for initialization.
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};
