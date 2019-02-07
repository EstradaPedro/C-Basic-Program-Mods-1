// Chapter 4 Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exercise 1 --> Write a program using vectors and iterators that allow a user to maintain a list of his or her fav games
// --> Add, remove, and list all of the games
// Exercise 2 --> What is wrong with the following code if Scores is also a vector
// Exercise 3 --> Write Pseudocode for the Word Jumble Program (Basic)

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cout << "**********Exercise 1**********\n";
	vector<string> gameList; // will contain the list of games
	gameList.push_back("KH3"); // for testing purposes
	gameList.push_back("KH2"); // for testing purposes
	vector<string>::iterator listIterator; // to navigate through the list of games
	vector<string>::const_iterator iter; // for loop purposes

	cout << "Wecome to the Game List program\n\n";
	cout << "To List all your current games enter 1\n";
	cout << "To add a game enter 2\n";
	cout << "To remove a game enter 3 (Caps matter)\n";
	cout << "To quit the proram enter anything else\n";
	cout << "Input: ";
	int choice;
	cin >> choice;

	enum options{ LIST = 1, ADD, REMOVE };
	string game;
	int position;

	while (choice == 1 || choice == 2 || choice == 3)
	{
		switch (choice)
		{
			case LIST:
				cout << "\nGame List:\n";
				for (iter = gameList.begin(); iter != gameList.end(); ++iter)
				{
					cout <<" " << *iter << endl; // prints out the value inside the vector string at the given index
				}
				break;
			case ADD:
				cout << "Enter the game you would like to enter into the list: ";
				cin >> game;
				gameList.insert(gameList.end(), game);
				cout << "\nGame List:\n";
				for (iter = gameList.begin(); iter != gameList.end(); ++iter)
				{
					cout << " " << *iter << endl; 
				}
				break;
			case REMOVE:
				cout << "Enter the game you would like to delete from the list: ";
				cin >> game;
				iter = find(gameList.begin(), gameList.end(), game); // finds the game that the user inputted
				
				if (iter != gameList.end())
				{
					cout << "Game Found\n";
					position = iter - gameList.begin(); // gives the position of the index
					//cout << "The position is: " << position << "\n";
					cout << "Deleting the game " << game << "\n";
					gameList.erase((gameList.begin() + position));
				}
				else
				{
					cout << "Game not found\n";
				}
				cout << "\nGame List:\n";
				for (iter = gameList.begin(); iter != gameList.end(); ++iter)
				{
					cout << " " << *iter << endl;
				}
				break;
			default:
				cout << "Wrong Input\n";
				break;

		}
		cout << "Input: ";
		cin >> choice;
	}
	cout << "Thank your for using the game list program." << endl;


	cout << "**********Exercise 2**********\n";
	/*vector<int> ::iterator iter;
	vector<int> scores;
	//increment each score
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		iter++;
	} // This increments twice meaning that it will always skip one place */
	cout << "**********Exercise 3**********\n";
	/*
		Pseudocode 1:
			Create a list of games
			Give the user options to list, add, or remove the games
			While the user doesn't quit the menu
				If list, list all the games currently
				Else if add let the user add games and show the current list of games
					Ask the user for the game to be added
					Add the game to the list of games
					Give the user the list of games
				Else let the user remove games and show the current list of games
					Ask the user for the game to be removed
					Find the game in the list
					If found delete the game
					Else tell the user that it wasn't found
					Give the user the list of games
			Thank the user for using the program

		Pseudocode 3 --> Word Jumble:
			Create a list of words and hints respectively
			Get a word from the list to be the guessed word
			Scramble the word
			Start the game
			Give the jumbled word to the player
			Ask for the user to guess the word
			While the user does not guess the word and doesnt quit
				If the user asks for a hint give him the hint that corresponds to the word
				else tell the user that they guessed incorrectly
				Ask the user for another guess
			If the user does guess the word congratulate the user and end the program
	*/
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
