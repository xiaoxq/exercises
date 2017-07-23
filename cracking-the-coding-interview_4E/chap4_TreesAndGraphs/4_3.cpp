/*
 * 4_3.cpp
 *
 *  Created on: 2013-4-18
 *      Author: beet
 */

#include <queue>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node( int dat )
	{
		data = dat;
		left = right = NULL;
	}
};

// [left,...,right)
Node* toTree( int* sortedArray, int left, int right )
{
	if( left==right )
		return NULL;

	int middle = (left+right)/2;
	Node* root = new Node( sortedArray[middle] );
	root->left = toTree(sortedArray,left,middle);
	root->right = toTree(sortedArray,middle+1,right);
	return root;
}

///////////////// TEST /////////////////
#include <stdio.h>
void printTree(Node* root)
{
	printf("================================\n");
	queue<Node*> visitingQueue;
	visitingQueue.push(root);
	// NULL is like an EOL
	visitingQueue.push(NULL);

	while( true )
	{
		Node* current = visitingQueue.front();
		visitingQueue.pop();

		if( current!=NULL )
		{
			printf("%d ", current->data);
			if(current->left != NULL)
				visitingQueue.push( current->left );
			if(current->right != NULL)
				visitingQueue.push( current->right );
		}
		else
		{
			printf("\n");
			if( visitingQueue.empty() )
				break;

			// add another EOL
			visitingQueue.push(NULL);
		}
	}
}

void releaseTree(Node* root)
{
	if(root==NULL)
		return;
	releaseTree( root->left );
	releaseTree( root->right );
	delete root;
}

int main()
{
	int sortedArray[] = { 1,2,3,4,5,6,7,8,9,10 };
	Node* root;
	root = toTree(sortedArray,0,1); printTree( root ); releaseTree(root);
	root = toTree(sortedArray,0,2); printTree( root ); releaseTree(root);
	root = toTree(sortedArray,0,3); printTree( root ); releaseTree(root);
	root = toTree(sortedArray,0,7); printTree( root ); releaseTree(root);
	root = toTree(sortedArray,0,10); printTree( root ); releaseTree(root);

	return 0;
}
