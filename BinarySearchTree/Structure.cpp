#include "stdafx.h"
#include "Structure.h"
#include <string>
#include <iostream>

using namespace std;

Structure::Structure()
{
}

// This min function is the public function for min. It calls the private method tree min. Min passes the root node
// to get the min of the entire tree. This allows the program to use tree min from any sub tree in other functions.
string Structure::Min()
{
	// If the tree is empty do not try to call tree min just respond with empty tree.
	if (root == nullptr)
	{
		strOutput = "Tree is empty";
		return strOutput;
	}
	else
	{
		currentNode = TreeMin(root);
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
		return strOutput;
	}

}

// List just calls the traveral method.
void Structure::List()
{
	Traversal(root);
}

// Public function that calls the private function tree insert.
void Structure::Insert(string strWord)
{
	treeInsert(strWord);
}

// Public method that calls the private tree search function. If we end up with a null pointer then we did not find 
// the string in the tree. Passing with strings allows me to keep Nodes completely hidden from main
string Structure::Search(string strWord)
{
	treeSearch(strWord);
	if (currentNode == nullptr)
	{
		strOutput = strWord + " 0";
	}
	else
	{
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
	}

	return strOutput;
}

// Public method that calls the tree successor function. This function also uses the tree search function to find where
// in the tree it should start. If the string entered does not exist in the tree then alert the user. If we fall off the end
// of the tree then there is no successor.
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
		if (currentNode == nullptr)
		{
			strOutput = "No successor was found for " + strWord;
		}
		else
		{
			strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
			
		}
		return strOutput;

	}

}

// This traversal function follows the pseudo code from the slides. It recursively solves left sub tree, output self, solve 
// right sub tree. 
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
	while (startNode->GetLeftNode() != nullptr)
	{
		startNode = startNode->GetLeftNode();
	}
	return startNode;
}

Node* Structure::TreeSuccessor(Node* startNode)
{
	if (startNode == nullptr)
	{
		return nullptr;
	}
	if (startNode->GetRightNode() != nullptr)
	{
		return TreeMin(startNode->GetRightNode());
	}

	pastNode = startNode;
	currentNode = startNode->GetLastNode();

	while (currentNode != nullptr && pastNode == currentNode->GetRightNode())
	{
		pastNode = currentNode;
		currentNode = currentNode->GetLastNode();

	}
	return currentNode;

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
