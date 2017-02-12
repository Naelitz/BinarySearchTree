// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
int intInput;
string strInput;
string line;
void GetInput();
int intCounter = 1;
int main()
{
	//Node FirstNode;
	//Node* pntCurrentNode;
Start:
	
	GetInput();
	if (strInput < "and")
	{
		cout << "Less Than" << endl;
	}
	else if (strInput == "and")
	{
		cout << "Equal Too" << endl;
	}
	else
	{
		cout << "Greater Than" << endl;
	}
	cout << strInput << endl;
	goto Start;




	return 0;
}

void GetInput()
{
	cout << "Enter a value" << endl;
	cin >> strInput;
}

