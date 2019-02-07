// Chapter2Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1: Rewrite the Menu Chooser Program using an enumeration to represent the difficulty levels --> Choice will be of type int
// Exercise 2: Find the wrong thing with the written loop
// Exercise 3: Write a new version of Guess my Number program in which the player and cpu switch roles
// --> Player picks a number and the computer must guess what it is

#include "pch.h"
#include <iostream>
#include <cstdlib> // to generate random #
#include <ctime> // for seeding


using namespace std;

int main()
{
	cout << "**********Exercise 1********** \n";
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Medium\n";
	cout << "3 - Hard\n";

	int choice;
	enum difficulty {Easy = 1,Medium,Hard}; // initialize Easy to 1 because enum starts at 0
	cout << "Choice: ";
	cin >> choice;

	switch (choice) // Instead of writing 1 2 3 for the case statements write Easy,Medium,Hard
	{
	case Easy:
		cout << "You picked Easy.\n";
		break;
	case Medium:
		cout << "You picked Medium.\n";
		break;
	case Hard:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice.\n";
	}

	//2

	cout << "\n**********Exercise 2********** \n";
	/*int x = 0;
	while (x)
	{
		++x;
		cout << x << endl;
	} */ // the while loop has no end condition so it will loop forever

	//3
	cout << "\n**********Exercise 3********** \n";
	/*srand(static_cast<unsigned int>(time(0))); // seeds rng
	int secretNumber = rand() % 100 + 1; // random number from 1 to 100
	int tries = 0;
	int guess;

	cout << "\tWelcome to Guess my Number\n\n";

	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout << "Too High!\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too Low!\n\n";
		}
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
		}
	} while (guess != secretNumber); */ // Original Program


	int secretNumber; // user enters a number for the cpu to guess
	int computerGuess;
	int tries = 0;
	cout << "Welcome to Guess my Number\n\n";
	cout << "Enter the number for the CPU to guess from 1 - 100: ";
	cin >> secretNumber;
	srand(static_cast<unsigned int>(time(0))); // seeds rng, if put in the loop it messes things up
	do
	{
		computerGuess = rand() % 100 + 1; // random number from 1 to 100 for the computer to get a number to guess
		cout << "Computer  Guess: " << computerGuess << "\n";
		++tries;

		if (computerGuess > secretNumber)
		{
			cout << "Too High!\n\n";
		}
		else if (computerGuess < secretNumber)
		{
			cout << "Too Low!\n\n";
		}
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
		}
	} while (computerGuess != secretNumber); // works but the cpu doesnt get rid of the guesses it has made

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
