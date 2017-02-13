#include "stdafx.h"
#include "Structure.h"
#include <string>

Structure::Structure()
{
}

void Structure::Insert(string strWord)
{

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
