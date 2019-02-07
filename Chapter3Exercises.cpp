// Chapter3Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1 --> Add a Scoring system to the Word Jumble Program, Point Value = length of word and -1 point for hint
// Exercise 2 --> Find what's wrong with the code
// Exercise 3 --> Find what's wrong with the code

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() // ENUMERATIONS are unsigned int constants their respective values starts at 0 and increments by 1
{
	cout << "**********Exercise 1**********\n";

	enum fields { WORD, HINT, NUM_FIELDS }; // Defines what the arrays are made off Example word is the first feild and hint is the second field and the # of fields is 2 and since it starts 0,1,(2) is used for the array size
	const int NUM_WORDS = 5; // the amount of how many different words/hints you want in the game
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall","Do you feel you're banging your head against something?"},
		{"glasses","These might help you see the answer."},
		{"labored","Going slowly, is it?"},
		{"persistent","Keep at it."},
		{"jumble","It's what the game is all about."}
	};

	//pick random word
	srand(static_cast<unsigned int>(time(0))); // seeding
	int choice = (rand() % NUM_WORDS); // chooses one of the row #
	string theWord = WORDS[choice][WORD]; // word to guess
	string theHint = WORDS[choice][HINT]; // the hint for the word being guessed
	int wordValue = theWord.length();

	//Jumbling the word
	string jumble = theWord; // copies the word to a new string called jumble
	int length = jumble.size(); // for loop purposes
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length); // lets say length is 4 gets random # for the first index
		int index2 = (rand() % length); // for second index
		char temp = jumble[index1]; // new char made to hold the index value of the random #  EX. temp now holds 'T'
		jumble[index1] = jumble[index2]; // index1 value changes to index 2 value lets say it was 'T' and 2 was 'S' now we have 'S' and 'S'
		jumble[index2] = temp; // now the value of index 2 is changed to the temp which was 'T' now we have 'S' 'T' they were swaped
	}
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint, every hint is -1 to your Score.\n";
	cout << "Enter 'quit' to quit the game.\n";
	cout << "The word value is: " << wordValue << "\n";
	cout << "The jumble is: " << jumble; // prints the jumble word out

	string guess; // to hold the players guess
	cout << "\n\nYour guess: ";
	cin >> guess; // user input

	//Game loop
	while ((guess != theWord) && (guess != "quit")) // runs only if the player is not correct and didnt enter quit
	{
		if (guess == "hint")
		{
			cout << theHint; // if the player entered hint then the hint of the word is printed out
			wordValue -= 1;
		}
		else
		{
			cout << "Sorry,that's not it.";
		}
		cout << "\n\nYour guess: "; // continues the loop inside it after getting the initial guess to start the loop
		cin >> guess;
	}
	if (guess == theWord) // only runs if the guess was correct and no quit was entered
	{
		cout << "\nThat's it! You guessed it!\n";
		cout << "Your final score is: " << wordValue << "\n";
	}
	cout << "\nThanks for playing.\n"; // runs if the player wins or quits

	cout << "**********Exercise 2**********\n";
	string phrase = "Hello";
	for (int i = 0; i <= phrase.size(); ++i) // With the = Sign you get a blank character at the end, without it get only Hello
	{
		cout << "Character at position " << i << " is: " << phrase[i] << endl;
	}

	cout << "**********Exercise 3**********\n";

	/* const int ROWS = 2;
	const int COLUMNS = 3;
	char board[COLUMNS][ROWS] = { {'O','X','0'},{' ','X','X'} }; // It should be [ROWS][COlUMNS] and have 2 rows and 3 columns
	--> in this case we have 3 rows and 2 columns and it doesnt match what we wanted to initialize */

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
