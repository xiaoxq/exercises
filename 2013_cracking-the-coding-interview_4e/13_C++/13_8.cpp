/*
 * 13_8.cpp
 *
 *  Created on: 2013-5-17
 *      Author: beet
 */

#include <queue>
#include <map>
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

// it may not be a tree
Node* copy( Node* head )
{
	if(head==NULL)
		return NULL;

	Node* newHead = new Node;
	newHead->left = copy(head->left);
	newHead->right = copy(head->right);
	return newHead;
}

///////////////// TEST /////////////////
#include <stdio.h>
void printNode(Node* head)
{
	if(head)
	{
		printf( "%8x( ", head );
		printNode(head->left);
		printf( ", " );
		printNode(head->right);
		printf( " )" );
	}
	else
		printf("NULL");
}

void testNode(Node* head)
{
	// source structure
	printNode(head);
	printf("\n===============\n");
	printNode( copy(head) );
	printf("\n");
	// Note: destruct the copied structure here
}

int main()
{
	Node node[6];
	node[0].left = &(node[1]);
	node[0].right = &(node[2]);
	node[2].left = &(node[3]);
	node[2].right = &(node[4]);
	node[3].right = &(node[5]);
	testNode( node );
	return 0;
}
