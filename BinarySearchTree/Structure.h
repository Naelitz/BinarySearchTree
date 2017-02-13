#pragma once
#include "Node.h"
#include <string>
class Structure
{
public:
	void Insert(string strWord);
	void Delete();
	Node* Search(string strWord);
	Node Min();
	Node Max();

	Structure();
	~Structure();
private:
	Node* root;
	Node* currentNode;
	void Insert(string strWord, Node newNode);
};

