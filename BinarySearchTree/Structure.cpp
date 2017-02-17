#include "stdafx.h"
#include "Structure.h"
#include <string>
#include <iostream>

using namespace std;

Structure::Structure()
{
}

string Structure::Min()
{
	currentNode = TreeMin(root);
	strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
	return strOutput;
}

void Structure::List()
{
	Traversal(root);
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

string Structure::Next(string strWord)
{
	currentNode = treeSearch(strWord);
	if (currentNode == nullptr)
	{
		strOutput = "Input string not found";
		return strOutput;
	}
	else
	{
		currentNode = TreeSuccessor(currentNode);
		if(currentNode == nullptr)
		{
			strOutput = "No successor was found for " + strWord;
		}
		else
		{
			strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
			return strOutput;
		}
		
	}
	
}

void Structure::Traversal(Node* startNode)
{
	if (startNode != nullptr)
	{
		Traversal(startNode->GetLeftNode());
		cout << startNode->GetValue() << " " << startNode->GetOccurences() << endl;
		Traversal(startNode->GetRightNode());
	}
}

Node* Structure::TreeMin(Node* startNode)
{
	while(startNode->GetLeftNode() != nullptr)
	{
		startNode = startNode->GetLeftNode(); 
	}
	return startNode;
}

Node* Structure::TreeSuccessor(Node* startNode)
{
	if (startNode == nullptr)
	{
		cout << "Tree is empty" << endl;
	}
	else
	{
		if (startNode->GetRightNode() != nullptr)
		{
			pastNode = startNode;
			return TreeMin(startNode->GetRightNode());
		}
		else
		{
			pastNode = startNode->GetLastNode();
		}
		while (pastNode != nullptr && startNode == pastNode->GetRightNode())
		{
			startNode = pastNode;
			pastNode = pastNode->GetLastNode();

		}
		if(startNode->GetLeftNode() != nullptr && startNode == pastNode->GetLeftNode())
		{
			return pastNode;
		}
		else
		{
			currentNode = nullptr;
			return currentNode;
		}
		
	}
}

Node* Structure::treeSearch(string strWord)
{
	currentNode = root;
	while (currentNode != nullptr)
	{
		if (currentNode->GetValue() == strWord)
		{
			return currentNode;
		}
		else if (currentNode->GetValue() > strWord)
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
			return;
		}
		else if (currentNode->GetValue() > strWord)
		{
			currentNode = currentNode->GetLeftNode();
		}
		else
		{
			currentNode = currentNode->GetRightNode();
		}
	}
	auto newNode = new Node(strWord);
	newNode->SetLastNode(pastNode);
	if (pastNode == NULL)
	{
		root = newNode;
	}
	else if (newNode->GetValue() < pastNode->GetValue())
	{
		pastNode->SetLeftNode(newNode);
	}
	else
	{
		pastNode->SetRightNode(newNode);
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
