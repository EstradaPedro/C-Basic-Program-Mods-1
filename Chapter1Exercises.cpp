// Chapter1Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1 --> Six Variables Created 3 good names and 3 bad names --> Write why they are bad
// 2 --> Explain the result of what the line does before running it
// 3 --> Write a program that gets three game scores from the user and displays the average.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//1
	int _test1; // dont start with _
	int test11; // works 
	int testing; // good
	int test2; // works
	int t; // not descriptive enough
	int Test1; // try to keep the first letter lowercase

	cout << "**********Exercise 1********** \n";
	cout << "Good naming variables:\n";
	cout << "1) test11 \n2) testing\n3)test2 \n";
	cout << "Bad naming variables:\n";
	cout << "1) _test1 \n2) t \n3)Test1 \n\n";

	//  2
	cout << "**********Exercise 1********** \n";
	cout << "Seven divided by three is (7/3) " << 7 / 3 << endl; // prints 2 (int)
	cout << "Seven divided by three is (7.0/3) " << 7.0 / 3 << endl; // prints the decimal of 7.0 / 3 (double)
	cout << "Seven divided by three is (7.0/3.0) " << 7.0 / 3.0 << endl; //prints the decimal of 7.0/3.0 (double)

	//3
	double gameScore1;
	double gameScore2;
	double gameScore3;
	double gameTotal;
	double gameAverage;
	cout << "\n**********Exercise 3********** \n";
	cout << "This program gets 3 user inputs and prints out the average score\n";
	cout << "Enter First game score: ";
	cin >> gameScore1;
	cout << "\nEnter second game score: ";
	cin >> gameScore2;
	cout << "\nEnter third game score: ";
	cin >> gameScore3;
	gameTotal = gameScore1 + gameScore2 + gameScore3;
	gameAverage = gameTotal / 3.0;
	cout << "\nThe game average is: " << gameAverage << endl;
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
