// Chapter5Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1 --> What is wrong with the following code
// Exercise 2 --> Rewrite the Hangman from CH4 using functions. Include a function to get the guess and one to determine
// --> if said word is in the secret word
// Exercise 3 --> Usind default arguments write a function that asks the user for a # and returns that #
// --> function should accept a string prompt from the calling code, if the caller doesnt use a string than the function
// --> gives a generic prompt. Next using function overloading write a function that achieves the same result

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype> // provides functions to convert characters to uppercase

using namespace std;

char getGuess(string question); // func prototype
bool correctGuess(char letter, const string word);
//void guessExam(const string word, string current, char letter, int tries); used for chapter 6

int getNumber(string question = "Enter a number: ");
void getNumber(int num);

int main()
{
	cout << "**********Exercise 1**********\n";

	// int askNumber(int low = 1, int high); // this is a function prototype, if something is initialized then the remaining members must
	// also be initialized

	cout << "**********Exercise 2**********\n";
	const int MAX_WRONG = 8; // the max number of wrong guesses allowed

	vector<string> words; //collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end()); // randomies the order of the strings in the vector
	const string THE_WORD = words[0]; // word to guess // the string copied is the first one in the vector
	int wrong = 0; // # of incorrect guesses
	string soFar(THE_WORD.size(), '-'); // used to show the # of words guessed so far in the string default value tothem is '-'
	string used = ""; // used to show the letters guessed

	//Starting main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) // runs before the player guesses to show the interface
	{
		cout << "\nYou have " << (MAX_WRONG - wrong);
		cout << " Incorrect guesses left.\n";
		cout << "\nYou've guessed the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;


		char guess = getGuess("\n\nEnter your guess: "); // initialize the first guess by calling the function
		while (used.find(guess) != string::npos) // if the word guessed is not in the string of used words this runs
		{
			cout << "\nYou've already guessed " << guess << endl;
			guess = getGuess("\n\nEnter your guess: ");
		}
		used += guess; //adds the guessed character to used

		//guessExam(THE_WORD, soFar, guess, wrong); used for chapter 6
		if (correctGuess(guess,THE_WORD))
		{
			cout << "That's right! " << guess << " is in the word.\n";

			//update So Far
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry. " << guess << " isn't in the word.\n";
			++wrong;
		} 
	}
	//Ending
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou've been hanged!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}
	cout << "\nThe word was " << THE_WORD << endl;
	
	cout << "**********Exercise 3**********\n";
	int num;
	int num2;
	int num3;
	cout << "Default Prompt: ";
	num = getNumber();
	cout << "The Number received from the function is: " << num << "\n\n";
	cout << "User entered Prompt: ";
	num2 = getNumber("Enter a new number: ");
	cout << "The Number received from the function is: " << num2 << "\n\n";

	cout << "Enter a new num to show function overloading: ";
	cin >> num3;
	getNumber(num3);
	return 0;
}

char getGuess(string question)
{
	char guess;
	cout << question;
	cin >> guess;
	guess = toupper(guess); // make the guess into uppercase letters
	return guess;
}

bool correctGuess(char letter, const string word) //Determines if the players guesed word is in the secret word
{
	return word.find(letter) != string::npos;
}

int getNumber(string question)
{
	int number;
	cout << question;
	cin >> number;
	return number;
}
void getNumber(int num)
{
	cout << "The number passed to the void getNumber function is " << num << endl;
}
/*void guessExam(const string word, string current, char letter, int tries) // word = THE_WORD, current = soFar, letter = guess
{
	if (word.find(letter) != string::npos)
	{
		cout << "That's right! " << letter << " is in the word.\n";

		//update So Far
		for (int i = 0; i < word.length(); ++i)
		{
			if (word[i] == letter)
			{
				current[i] = letter;
			}
		}
	}
	else
	{
		cout << "Sorry. " << letter << "isn't in the word.\n";
		++tries;
	}
} */ // This passes by value and not by reference, this could be changed to pass by reference but that is chapter 6
// for use in chapter 5 if i get back to this

// Pseudocode 2 & 3
/*
	2:
	Create a list of words to be guessed from
	Set a limit of wrong tries
	Show the guessed letters and the currently guessed word
	Get the user to input a letter
	While the word is not guessed and the # of tries is not 0 continue asking the user for a letter
		If the letter is already guessed ask the user for another letter
		If the letter is not guessed and is in the word reveal the letter in the word
		Else subtract a try and ask for another letter if tries is not 0
	If the user did not guess the word show a defeat
	Else show the word and a Victory

	3:
	Ask the user for a number
	Print out the number
*/
