/*
 * 4_5.cpp
 *
 *  Created on: 2013-4-19
 *      Author: beet
 */

#ifndef NULL
#define NULL 0
#endif

// binary search tree node
struct BSTNode
{
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
	int data;
};

BSTNode* findNext( BSTNode* node )
{
	if( node==NULL )
		return NULL;
	// it's the minimum of right subtree
	if( node->parent==NULL || node->right!=NULL )
	{
		BSTNode* mini = node->right;
		if( mini )
			while(mini->left)
				mini = mini->left;
		return mini;
	}

	// I'm a left child
	if( node->parent->left == node )
		return node->parent;

	// I'm a right child, my next is also the next of my parent tree
	node->parent->right = NULL;
	BSTNode* result = findNext(node->parent);
	// recover the change
	node->parent->right = node;
	return result;
}

