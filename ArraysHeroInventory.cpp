// ArraysHeroInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
// An array of string

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main() // arrays can be intilized like string inventory[MAX_ITEMS] = ("sword","shield") this is the same as down but with less code
{			// if inventory[] = ("sword") the array will have a size of 1 only
	const int MAX_ITEMS = 10; //sets the limit to the array to 10
	string inventory[MAX_ITEMS]; // creates an array of type string with the name inv and with a size of Max items(10)

	int numItems = 0; // to know the # of items currently in the array
	inventory[numItems++] = "sword"; // the first item is set and will increment the index after assigning sword to index 0
	inventory[numItems++] = "armor"; // repeat the postfix increments the index after the current index is assigned a string in this case
	inventory[numItems++] = "shield";

	cout << "Your Items:\n";
	for (int i = 0; i < numItems; ++i) // goes through the array but only goes through the max # of items in it
	{
		cout << inventory[i] << endl;
	}

	cout << "\nYou trade your sword for a battle axe. ";
	inventory[0] = "battle axe"; // the string at index 0 is changed
	cout << "\nYour items:\n";
	for (int i = 0; i < numItems; ++i) // goes through the array but only goes through the max # of items in it
	{
		cout << inventory[i] << endl;
	}

	cout << "\nThe item name '" << inventory[0] << "' has";
	cout << inventory[0].size() << " letters in it.\n"; // the length of the string at index 0 is given

	cout << "\nYou find a healing potion.";
	if (numItems < MAX_ITEMS) // if the array has not reach its limit then the num of item increases 
	{
		inventory[numItems++] = "healing potion";
	}
	else // if no room this prints
	{
		cout << "You have too many items and can't carry another.";
	}
	cout << "\nYour items:\n";
	for (int i = 0; i < numItems; ++i) // goes through the array but only goes through the max # of items in it
	{
		cout << inventory[i] << endl;
	}
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
