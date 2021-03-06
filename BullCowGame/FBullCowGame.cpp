#pragma once

#include "FBullCowGame.h"
#include <map>

// To make syntax Unreal friendly.
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap <int32, int32> WordLengthToMaxTries
	{
		{ 3,4 },{ 4,7 },{ 5,10 },{ 6,15 },{ 7,20 }
	};
	return WordLengthToMaxTries[GetHiddenWordLength()];
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
	return bGameIsWon;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1)
	{
		return true;
	}

	TMap <char, bool> LetterSeen;

	for (auto Letter : Word) // "For each Letter in Word."
	{
		Letter = tolower(Letter);

		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	// For special cases, e.g. when \0 in entered.
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	// If only lowercase letters found.
	return true;
}

EGuessStatus FBullCowGame::CheckGuessIsValid(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

void FBullCowGame::Reset()
{
	// This must be an isogram.
	const FString HIDDEN_WORD = "plane"; 

	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

// Receives a valid guess, increments turn and returns count.
FBullsCowsCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullsCowsCount BullsCowsCount;

	// Loop through all letters in the hidden word.
	for (int32 HiddenWordChar = 0; HiddenWordChar < GetHiddenWordLength(); HiddenWordChar++)
	{
		// Compare letters against the guess.
		for (int32 GuessChar = 0; GuessChar < GetHiddenWordLength(); GuessChar++)
		{
			if (Guess[GuessChar] == MyHiddenWord[HiddenWordChar]) 
			{
				// if they're in the same place
				if (HiddenWordChar == GuessChar) 
				{
					BullsCowsCount.Bulls++;
				}
				else 
				{
					BullsCowsCount.Cows++;
				} 
			}
			
			
		}
	}

	if (BullsCowsCount.Bulls == GetHiddenWordLength())
	{
		bGameIsWon = true;
	}

	return BullsCowsCount;
}
