// BinarySearchTree.cpp : Defines the entry point for the console application.
//
// Author: David Naelitz
// EECS 2510 Non-Linear Data Structures
// Date: February 10, 2017

#include "stdafx.h"
#include "Node.h"
#include "Structure.h"
#include <iostream>
#include <string>

using namespace std;

void GetCommand();
void GetParameter();

Structure searchStructure;
string strInput;
string strOutput;
int intCounter;

int main()
{
Start: // Gives a start point to go back to receiving a command

	GetCommand();

	// If the command that comes in cin does not require a parameter, then run further logic before taking any more input
	// This will also help when a no parameter command is entered but a parameter is typed in the console it will
	// see it as an invalid command on the next pass through.
	if (strInput == "min" || strInput == "max" || strInput == "list" || strInput == "help" || strInput == "exit")
	{
		// Run the min function
		if (strInput == "min")
		{
			cout << searchStructure.Min() << endl;
		}
		else if (strInput == "max")
		{
			cout << searchStructure.Max() << endl;
		}
		else if (strInput == "list")
		{
			searchStructure.List();
		}
		// Simplly print command options to the console window.
		else if (strInput == "help")
		{
			cout << "insert <string>" << endl;
			cout << "delete <string>" << endl;
			cout << "search <string>" << endl;
			cout << "min" << endl;
			cout << "max" << endl;
			cout << "next <string>" << endl;
			cout << "prev <string>" << endl;
			cout << "list" << endl;
			cout << "help" << endl;
			cout << "exit" << endl;
		}
		else if (strInput == "exit")
		{
			goto Exit;
		}
		
	}
	// Now check for a command that requires a parameter. This means that we will get another input from the console 
	// before we execute further code. 
	else if (strInput == "insert" || strInput == "delete" || strInput == "search" || strInput == "next" || strInput == "prev")
	{
		if (strInput == "insert")
		{
			GetParameter();
			searchStructure.Insert(strInput);
		}
		else if (strInput == "delete")
		{
			cin >> strInput;
			strOutput = searchStructure.Delete(strInput);
			cout << strOutput << endl;
		}
		else if (strInput == "search")
		{
			cin >> strInput;
			strOutput = searchStructure.Search(strInput);
			cout << strOutput << endl;
			
		}
		else if (strInput == "next")
		{
			cin >> strInput;
			strOutput = searchStructure.Next(strInput);
			cout << strOutput << endl;
		}
		else if (strInput == "prev")
		{
			cin >> strInput;
			strOutput = searchStructure.Prev(strInput);
			cout << strOutput << endl;
		}
	}
	else // The input did not match any of the allowable commands
	{
		cout << "Invalid command please try again" << endl;
	}
	goto Start; // jump back to start since exit was not entered
	Exit:
	return 0;
}

void GetCommand()
{
	cout << "Enter a command" << endl;
	cin >> strInput;
	for (intCounter = 0; intCounter < strInput.size(); intCounter++)
	{
		strInput[intCounter] = tolower(strInput[intCounter]);
	}
}

void GetParameter()
{
	cin >> strInput;
}

