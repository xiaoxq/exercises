/*
 * 4_1.cpp
 *
 * O(n), the solution in book is O(2n)
 *
 *  Created on: 2013-4-18
 *      Author: beet
 */

#include<queue>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node* left;
	Node* right;

	Node()
	{
		left = right = NULL;
	}
};

bool checkBalanced(Node* root)
{
	if( root==NULL )
		return true;

	queue<Node*> visitingQueue;
	visitingQueue.push(root);
	// NULL is like an EOL
	visitingQueue.push(NULL);

	int minLevel = -1, curLevel = 1;
	while( true )
	{
		Node* current = visitingQueue.front(); visitingQueue.pop();
		// end of one level
		if( current==NULL )
		{
			if( visitingQueue.empty() )
				break;
			++curLevel;
			visitingQueue.push( NULL );
		}
		else
		{
			// find a leaf
			if( current->left==NULL && current->right==NULL )
			{
				if( minLevel<0 )
					minLevel = curLevel;
			}
			else
			{
				if( minLevel>0 && minLevel<curLevel )
					return false;

				if( current->left )
					visitingQueue.push( current->left );
				if( current->right!=NULL )
					visitingQueue.push( current->right );
			}
		}
	}
	return true;
}

///////////////// TEST /////////////////
void releaseTree( Node* root )
{
	if(root==NULL)
		return;
	releaseTree(root->left);
	releaseTree(root->right);
	delete root;
	root = NULL;
}

#include <stdio.h>
int main()
{
	Node* root1 = new Node();
	printf("%d\n", checkBalanced(root1)); // true
	root1->left = new Node();
	printf("%d\n", checkBalanced(root1)); // true
	root1->right = new Node();
	printf("%d\n", checkBalanced(root1)); // true
	root1->left->right = new Node();
	printf("%d\n", checkBalanced(root1)); // true
	root1->left->right->left = new Node();
	printf("%d\n", checkBalanced(root1)); // false
	root1->left->left = new Node();
	printf("%d\n", checkBalanced(root1)); // false
	root1->right->left = new Node();
	printf("%d\n", checkBalanced(root1)); // true
	root1->right->right = new Node();
	printf("%d\n", checkBalanced(root1)); // true

	releaseTree(root1);
	return 0;
}
