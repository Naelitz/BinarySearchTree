#include "stdafx.h"
#include "Node.h"
#include <string>

using namespace std;

Node::Node()
{

}

// This is a constructor that a string is passed to so everything can happen at once.
Node::Node(string strInputValue)
{
	strValue = strInputValue;
}

// A public function that sets the value of its string contents
void Node::SetValue(string strNewWord)
{
	strValue = strNewWord;
}

// A public function that returns the string contents of this node
string Node::GetValue()
{
	return strValue;
}

// A public function that sets the right branch pointer to the node that is passed to it.
void Node::SetRightNode(Node* theNode)
{
	rightNode = theNode;
}

// A public function to do the opposite of set right node. This sets the left node pointer to the node that is passed to it.
void Node::SetLeftNode(Node* theNode)
{
	leftNode = theNode;
}

// A public function that sets the parent pointer.
void Node::SetLastNode(Node* theNode)
{
	lastNode = theNode;
}

// Just increments occurences by one.
void Node::IncrementOccurence()
{
	intOccurences++;
}

// decrements occurences by one
void Node::DecrementOccurences()
{
	intOccurences--;
}

// returns the count of occurences 
int Node::GetOccurences()
{
	return intOccurences;
}

// returns the pointer in the left branch of the node
Node* Node::GetLeftNode()
{
	return leftNode;
}

// returns the pointer in the right branch of the node
Node* Node::GetRightNode()
{
	return rightNode;
}

// returns the parent pointer
Node* Node::GetLastNode()
{
	return lastNode;
}

Node::~Node()
{
}
