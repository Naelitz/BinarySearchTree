#pragma once
#include "Node.h"
#include <string>
class Structure
{
public:
	void Insert(std::string strWord);
	void Delete();
	void List();
	std::string Search(std::string strWord);
	std::string Min();
	std::string Max();
	std::string Next(std::string strWord);
	std::string ReturnValue();
	Structure();
	~Structure();
private:
	Node* root;
	Node* currentNode;
	Node* pastNode;
	Node* treeSearch(std::string strWord);
	Node foundNode;
	void TreeMin(Node* startNode);
	void TreeMax(Node* startNode);
	void Traversal(Node* startNode);
	void treeInsert(std::string strWord);
	void treeDelete();
	std::string strOutput;
};

