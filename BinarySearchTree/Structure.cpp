#include "stdafx.h"
#include "Structure.h"
#include <string>

using namespace std;

Structure::Structure()
{
}

void Structure::Insert(string strWord)
{
	treeInsert(strWord);
}

string Structure::Search(string strWord)
{
	treeSearch(strWord);
	if (currentNode == NULL)
	{
		strOutput = strWord + " 0";
	}
	else
	{
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
	}
	
	return strOutput;
}

Node* Structure::treeSearch(string strWord)
{
	currentNode = root;
	while (currentNode != NULL)
	{
		if (currentNode->GetValue() == strWord)
		{
			return currentNode;
		}
		else if (currentNode->GetValue() < strWord)
		{
			currentNode = currentNode->GetLeftNode();
		}
		else
		{
			currentNode = currentNode->GetRightNode();
		}
	}
	return currentNode;
}

void Structure::treeInsert(string strWord)
{
	currentNode = root;
	pastNode = NULL;
	while (currentNode != NULL)
	{
		pastNode = currentNode;
		if (currentNode->GetValue() == strWord)
		{
			currentNode->IncrementOccurence();
		}
		else if (currentNode->GetValue() < strWord)
		{
			currentNode = currentNode->GetLeftNode();
		}
		else
		{
			currentNode = currentNode->GetRightNode();
		}
	}
	Node newNode(strWord);
	newNode.SetLastNode(pastNode);
	if (pastNode == NULL)
	{
		root = &newNode;
	}
	else if (newNode.GetValue() < pastNode->GetValue())
	{
		pastNode->SetLeftNode(&newNode);
	}
	else
	{
		pastNode->SetRightNode(&newNode);
	}

}

string Structure::ReturnValue()
{
	strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
	return strOutput;
}

Structure::~Structure()
{
}
