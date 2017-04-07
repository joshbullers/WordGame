// BullCowGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
void PrintGuess(std::string Guess);
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiation

int main()
{
	PrintIntro();
	bool bPlayAgain = true;
	do
	{
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
    return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// TODO change from FOR to WHILE loop once we are validating tries
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); // TODO make loop checking valid

		// Submit valid guess to the game
		// print number of bulls and cows

		PrintGuess(Guess);
	}

	// TODO summarize game
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I am thinking of?\n";
	std::cout << std::endl;
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	
	std::string Guess = "";

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGuess(std::string Guess)
{
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;
}