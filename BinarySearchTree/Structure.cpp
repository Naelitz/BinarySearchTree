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
	// The tree is not empty so run the tree min function starting at the root
	else
	{
		currentNode = TreeMin(root);
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
		return strOutput;
	}

}

// The inverse of min. If the tree is empty then say so, else run tree max starting at the root
string Structure::Max()
{
	if (root == nullptr)
	{
		strOutput = "Tree is empty";
		return strOutput;
	}
	else
	{
		currentNode = TreeMax(root);
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
	currentNode = treeSearch(strWord);
	// If the word is not found then current node will be a null pointer so let the user know that word exists zero
	// times in the tree
	if (currentNode == nullptr)
	{
		strOutput = strWord + " 0";
	}
	// else just output the node that was found
	else
	{
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
	}

	return strOutput;
}

// This is the public method that will call the tree predecessor function. This is also the opposite of the next method.
string Structure::Prev(string strWord)
{
	// as alot of the functions start. Use the search function to find the node we want to start from. 
	// if that node does not exist then alert the user of that.
	currentNode = treeSearch(strWord);
	if (currentNode == nullptr)
	{
		strOutput = strWord + " not found";
		return strOutput;
	}
	// If the starting node was found then make sure there is actually a predecessor, meaning it is not the beginning
	// of the list. If it has a predecessor then return the output string back to main
	else
	{
		currentNode = TreePredecessor(currentNode);
		if (currentNode == nullptr)
		{
			strOutput = "No predecessor was found for " + strWord;
		}
		else
		{
			strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
		}
		return strOutput;
	}
}

// Public method that calls the tree successor function. This function also uses the tree search function to find where
// in the tree it should start. If the string entered does not exist in the tree then alert the user. If we fall off the end
// of the tree then there is no successor.
string Structure::Next(string strWord)
{
	currentNode = treeSearch(strWord);
	if (currentNode == nullptr)
	{
		strOutput = strWord + " not found";
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

// This is the public delete method that starts off with using the search function to make sure that the node we want to delete
// actually exists in the list. As per instructions if the node does not exist it will output the word and a negative 1. 
// if we do have the word in the list then check the count because we want to only decrement the occurences if we have more then one
// if there is only one then we want to actually get rid of the node.
string Structure::Delete(string strWord)
{
	currentNode = treeSearch(strWord);
	if (currentNode == nullptr)
	{
		strOutput = strWord + " -1";
	}
	else if (currentNode->GetOccurences() > 1) // more then one occurence just decrement do not delete.
	{
		currentNode->DecrementOccurences();
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences());
	}
	else // only one occurence delete the node
	{
		strOutput = currentNode->GetValue() + " " + std::to_string(currentNode->GetOccurences() - 1);
		TreeDelete(currentNode);
	}
	
	return strOutput;

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

// Simple min method from the slides that continues down a tree from a start node to find the farthest left node
// passing a starting node allows this function to be called to solve sub trees as well as the entire tree.
Node* Structure::TreeMin(Node* startNode)
{
	while (startNode->GetLeftNode() != nullptr)
	{
		startNode = startNode->GetLeftNode();
	}
	return startNode;
}

// The inverse of tree min to go as far right as possible to find the max of the tree or a sub tree
Node* Structure::TreeMax(Node* startNode)
{
	while (startNode->GetRightNode() != nullptr)
	{
		startNode = startNode->GetRightNode();
	}
	return startNode;
}

// This is the private function that works with prev and hides the tree functionality
Node* Structure::TreePredecessor(Node* startNode)
{
	// if the start node is a null pointer then do not do anything with it just pass it back.
	if (startNode == nullptr)
	{
		return nullptr;
	}
	// start node exists so go left if possible to see if there is a lesser child node
	if (startNode->GetLeftNode() != nullptr)
	{
		return TreeMax(startNode->GetLeftNode());
	}
	// Getting to this line of code means that the start node exists but it does not have a lesser child node
	// It needs to start climbing back up the tree. If when climbing back up the tree we take a path back up a right branch
	// then that node is the predecessor.
	pastNode = startNode;
	currentNode = startNode->GetLastNode();
	while (currentNode != nullptr && pastNode == currentNode->GetLeftNode()) // this loop will break when we go up a right branch
	{
		pastNode = currentNode;
		currentNode = currentNode->GetLastNode();
	}
	return currentNode;
}

// This is the inverse of predecessor. We will check that the start exists, see if there is a right child node, and then climb up
// the tree until we follow a left branch up to find the successor.
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

// This is the private tree search method that will always start at the root and then head down the tree using the 
// BST properties to find the value we are looking for.
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

// This is the private tree insert function. This function works using a string passed to it because we do not want to 
// create the node until we know we actually need a new node. 
void Structure::treeInsert(string strWord)
{
	currentNode = root;
	pastNode = nullptr;
	// While the current pointer is not null continue through the tree
	while (currentNode != nullptr)
	{
		pastNode = currentNode;
		// If the current node matches the new word then we do not need a new node we just increment the occurences of the 
		// node we found.
		if (currentNode->GetValue() == strWord)
		{
			currentNode->IncrementOccurence();
			return;
		}
		// If the new word is less then the current node then follow the left branch down the tree
		else if (currentNode->GetValue() > strWord)
		{
			currentNode = currentNode->GetLeftNode();
		}
		// It was not equal or less then the current node so it must be greater so follow the right branch down the tree
		else
		{
			currentNode = currentNode->GetRightNode();
		}
	}
	// The program has broken out of the previous loop meaning that we have fallen off the bottom of the tree.
	// This means we need a new node because the word did not already exist in the tree.
	auto newNode = new Node(strWord);
	newNode->SetLastNode(pastNode); // Set the parent pointer to the last node we were on before falling off the tree
	if (pastNode == nullptr)
	{
		root = newNode; // if the past node is already null then we were inserting the root node
	}
	else if (newNode->GetValue() < pastNode->GetValue()) // Now decide if we are greater then or less then the node we fell from
	{
		pastNode->SetLeftNode(newNode);
	}
	else
	{
		pastNode->SetRightNode(newNode);
	}

}

// This is the private delete method. This method gets called when we have already checked that the occurences of the node
// are specifically one. So we will be deleting the node.
void Structure::TreeDelete(Node* startNode)
{
	if (startNode->GetLeftNode() == nullptr) 
	{
		Transplant(startNode, startNode->GetRightNode());
	}
	else if (startNode->GetRightNode() == nullptr)
	{
		Transplant(startNode, startNode->GetLeftNode());
	}
	else
	{
		auto successorNode = TreeMin(startNode->GetRightNode());
		if (successorNode->GetLastNode() != startNode)
		{
			Transplant(successorNode, successorNode->GetRightNode());
			successorNode->SetRightNode(startNode->GetRightNode());
			(successorNode->GetRightNode())->SetLastNode(successorNode);
		}
		Transplant(startNode, successorNode);
		successorNode->SetLeftNode(startNode->GetLeftNode());
		(successorNode->GetLeftNode())->SetLastNode(successorNode);
	}
}

// This is the transplant function taken from the slides. Nodes were named U and V to be easier to follow the example
// slides. 
void Structure::Transplant(Node* nodeU, Node* nodeV)
{
	if (nodeU->GetLastNode() == nullptr)
	{
		root = nodeV;
	}
	else if (nodeU == (nodeU->GetLastNode())->GetLeftNode())
	{
		(nodeU->GetLastNode())->SetLeftNode(nodeV);
	}
	else
	{
		(nodeU->GetLastNode())->SetRightNode(nodeV);
	}

	if (nodeV != nullptr)
	{
		nodeV->SetLastNode(nodeU->GetLastNode());
	}
}

Structure::~Structure()
{
}
