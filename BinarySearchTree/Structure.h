#pragma once
#include "Node.h"
#include <string>
class Structure
{
public:
	void Insert(std::string strWord);
	void Delete();
	Node* Search(std::string strWord);
	Node Min();
	Node Max();

	Structure();
	~Structure();
private:
	Node* root;
	Node* currentNode;
	void Insert(std::string strWord, Node newNode);
};

