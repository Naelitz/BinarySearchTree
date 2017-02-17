#pragma once
#include <string>
class Node
{
public:
	void SetValue(std::string strNewWord);
	std::string GetValue();
	void SetRightNode(Node* theNode);
	void SetLeftNode(Node* theNode);
	void SetLastNode(Node* theNode);
	void IncrementOccurence();
	void DecrementOccurences();
	int GetOccurences();
	Node* GetLeftNode();
	Node* GetRightNode();
	Node* GetLastNode();
	Node();
	Node(std::string strInputValue);
	~Node();
// The variables are set to private so that they can not be set outside of the class without using the appropriate
// getter and setter functions.
private:
	int intOccurences = 1;
	std::string strValue;
	Node* rightNode;
	Node* leftNode;
	Node* lastNode;
};

