#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGuessValid(FString)
{
	return false;
}

// Receives a valid guess, increments turn and returns count.
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// Increment turn number.
	MyCurrentTry++;

	// Setup return variable.
	BullCowCount BullCowCount;

	// Loop through all letters in the guess.
		// Compare letters against the hidden word.
	return BullCowCount;
}
