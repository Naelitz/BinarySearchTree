#pragma once
#include <string>
class Node
{
public:
	string strValue;
	int intOccurences = 1;
	Node* rightNode;
	Node* leftNode;
	Node* lastNode;
	void SetValue(string strNewWord);
	string GetValue();
	void SetRightNode(Node* theNode);
	void SetLeftNode(Node* theNode);
	void SetLastNode(Node* theNode);
	void IncrementOccurence();
	int GetOccurences();
	Node* GetLeftNode();
	Node* GetRightNode();
	Node* GetLastNode();
	Node();
	~Node();
};

