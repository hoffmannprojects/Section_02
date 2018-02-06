#pragma once
#include <string>

class FBullCowGame 
{
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool IsGuessValid(std::string);

	// Maybe useful in the future.
	//bool WantsToPlayAgain();
	//bool IsGuessCorrect();

private:

};