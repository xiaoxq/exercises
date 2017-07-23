/*
 * 4_4.cpp
 *
 * O(n)
 *
 *  Created on: 2013-4-19
 *      Author: beet
 */

#include <queue>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node* left;
	Node* right;
};

void levelToList( Node* root, vector< list<Node*> >& result )
{
	if( root==NULL )
		return;

	queue<Node*> visitingQueue;
	visitingQueue.push(root);
	// NULL is like an EOL
	visitingQueue.push(NULL);

	result.push_back( list<Node*>() );
	while(true)
	{
		Node* current = visitingQueue.front(); visitingQueue.pop();

		if( current!=NULL )
		{
			result.rbegin()->push_back( current );
			if(current->left!=NULL)
				visitingQueue.push( current->left );
			if(current->right!=NULL)
				visitingQueue.push( current->right );
		}
		else
		{
			if(visitingQueue.empty())
				break;

			// add another EOL and container
			visitingQueue.push(NULL);
			result.push_back( list<Node*>() );
		}
	}
}
