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

int main()
{
	int intInput;
	Structure searchStructure;
	string strInput;
	string strReturnValue;
	Node* nodeFound;
	string line;
	
	int intCounter = 1;
	//Node FirstNode;
	//Node* pntCurrentNode;
Start:

	GetCommand();

	if (strInput == "min" || strInput == "max" || strInput == "list" || strInput == "help" || strInput == "exit")
	{
		if (strInput == "min")
		{
			//todo: Write min function
		}
		else if (strInput == "max")
		{
			//todo: Write max function
		}
		else if (strInput == "list")
		{
			//todo: Write list function
		}
		else if (strInput == "help")
		{
			//todo: Write help function
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
			//todo: Write exit function
			goto Exit;
		}
		
	}
	
	else if (strInput == "insert" || strInput == "delete" || strInput == "search" || strInput == "next" || strInput == "prev")
	{
		if (strInput == "insert")
		{
			//todo: Write insert function
		}
		else if (strInput == "delete")
		{
			//todo: Write delete function
		}
		else if (strInput == "search")
		{
			//todo: Write search function
			cin >> strInput;
			nodeFound = searchStructure.Search(strInput);
			if (nodeFound = NULL)
			{
				cout << strInput << "  0" << endl;
			}
			else
			{
				cout << nodeFound->GetValue << "  " << nodeFound->GetOccurences << endl;
			}
			
		}
		else if (strInput == "next")
		{
			//todo: Write next function
		}
		else if (strInput == "prev")
		{
			//todo: Write the prev function
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

