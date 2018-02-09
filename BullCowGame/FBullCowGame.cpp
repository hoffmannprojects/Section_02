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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	// Setup return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the guess.
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// Compare letters against the hidden word.
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// if they match
			// increment bulls if they're in the same place
			if (Guess[j] == MyHiddenWord[j]) 
			{
				BullCowCount.Bulls++;
			}
			
			else 
			// increment cows if not
			if (Guess[i] == MyHiddenWord[j])
			{
				BullCowCount.Cows++;
			} 
			
		}
	}

	return BullCowCount;
}
