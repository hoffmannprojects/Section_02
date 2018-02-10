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

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessIsValid(FString) const
{
	return EWordStatus::Ok; //TODO: make actual error.
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

// Receives a valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	// Setup return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the guess.

	for (int32 HiddenWordChar = 0; HiddenWordChar < GetHiddenWordLength(); HiddenWordChar++)
	{
		// Compare letters against the hidden word.
		for (int32 GuessChar = 0; GuessChar < GetHiddenWordLength(); GuessChar++)
		{
			// if they match
			if (Guess[GuessChar] == MyHiddenWord[HiddenWordChar]) 
			{
				// if they're in the same place
				if (HiddenWordChar == GuessChar) 
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				} 
			}
			
			
		}
	}

	return BullCowCount;
}
