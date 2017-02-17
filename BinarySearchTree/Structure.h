#pragma once
#include "Node.h"
#include <string>
class Structure
{
public:
	void Insert(std::string strWord);
	std::string Delete(std::string strWord);
	void List();
	std::string Search(std::string strWord);
	std::string Min();
	std::string Max();
	std::string Prev(std::string strWord);
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
	void TreeDelete(Node* startNode);
	Node* TreeMin(Node* startNode);
	Node* TreeMax(Node* startNode);
	Node* TreePredecessor(Node* startNode);
	Node* TreeSuccessor(Node* startNode);
	void Traversal(Node* startNode);
	void treeInsert(std::string strWord);
	void Transplant(Node* nodeU, Node* nodeV);
	std::string strOutput;
};

