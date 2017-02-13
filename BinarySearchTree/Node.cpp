#include "Node.h"
#include "stdafx.h"
#include <string>

Node::Node()
{
}

void Node::SetValue(string strNewWord)
{
	strValue = strNewWord;
}

string Node::GetValue()
{
	return strValue;
}

void Node::SetRightNode(Node* theNode)
{
	rightNode = theNode;
}

void Node::SetLeftNode(Node* theNode)
{
	leftNode = theNode;
}

void Node::SetLastNode(Node* theNode)
{
	lastNode = theNode;
}

void Node::IncrementOccurence()
{
	intOccurences++;
}

int Node::GetOccurences()
{
	return intOccurences;
}

Node* Node::GetLeftNode()
{
	return leftNode;
}

Node* Node::GetRightNode()
{
	return rightNode;
}

Node* Node::GetLastNode()
{
	return lastNode;
}

Node::~Node()
{
}
