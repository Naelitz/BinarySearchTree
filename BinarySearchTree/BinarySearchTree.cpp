// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Structure.h"
#include <iostream>
#include <string>

using namespace std;

void GetCommand();
void GetParameter();

int intInput;
Structure searchStructure;
string strInput;
string strOutput;
string strReturnValue;
Node* nodeFound;
string line;

int intCounter = 1;

int main()
{

	//Node FirstNode;
	//Node* pntCurrentNode;
Start:

	GetCommand();

	if (strInput == "min" || strInput == "max" || strInput == "list" || strInput == "help" || strInput == "exit")
	{
		if (strInput == "min")
		{
			//todo: Write min function
			cout << searchStructure.Min() << endl;
		}
		else if (strInput == "max")
		{
			//todo: Write max function
			cout << searchStructure.Max() << endl;
		}
		else if (strInput == "list")
		{
			searchStructure.List();
		}
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
	
	else if (strInput == "insert" || strInput == "delete" || strInput == "search" || strInput == "next" || strInput == "prev")
	{
		if (strInput == "insert")
		{
			GetParameter();
			searchStructure.Insert(strInput);
		}
		else if (strInput == "delete")
		{
			//todo: Write delete function
		}
		else if (strInput == "search")
		{
			cin >> strInput;
			strOutput = searchStructure.Search(strInput);
			cout << strOutput << endl;
			
		}
		else if (strInput == "next")
		{
			//todo: Write next function
			cin >> strInput;
			strOutput = searchStructure.Next(strInput);
			cout << strOutput << endl;
		}
		else if (strInput == "prev")
		{
			//todo: Write the prev function
			cin >> strInput;
			strOutput = searchStructure.Prev(strInput);
			cout << strOutput << endl;
		}
	}
	else
	{
		cout << "Invalid command please try again" << endl;
	}
	goto Start;
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

