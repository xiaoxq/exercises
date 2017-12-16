/*
 * 4_6.cpp
 *
 *  Created on: 2013-4-19
 *      Author: beet
 */

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node* left;
	Node* right;
};

// O(logn)
bool findEigher( Node* root, Node* p, Node* q )
{
	if( root==NULL )
		return false;
	if( root==p || root==q )
		return true;
	return findEigher( root->left, p, q ) || findEigher( root->right, p ,q );
}

// O( (logn)^2 )
Node* findFirstCommonAncestor( Node* root, Node* p, Node* q )
{
	if( root==NULL || root==p || root==q )
		return root;

	// not in left, search right subtree
	if( !findEigher( root->left, p, q ) )
		return findFirstCommonAncestor( root->right, p, q );

	// not in right, search left subtree
	if( !findEigher( root->right, p, q ) )
		return findFirstCommonAncestor( root->left, p, q );

	// one in left and anthor in right
	return root;
}


