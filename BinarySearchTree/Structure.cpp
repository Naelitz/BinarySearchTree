#include "stdafx.h"
#include "Structure.h"
#include <string>

using namespace std;

Structure::Structure()
{
}

void Structure::Insert(string strWord)
{
	if (root == NULL)
	{
		root = new Node(strWord);
	}
}

Node* Structure::Search(string strWord)
{
	if (root == NULL)
	{
		return root;
	}
	currentNode = root;
}

Structure::~Structure()
{
}
