/*
 * 4_7.cpp
 *
 *  Created on: 2013-4-21
 *      Author: beet
 */

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node* left;
	Node* right;
	int data;
};

bool isMatch( Node* T1, Node* T2 )
{
	// T2 may be smaller
	if(T2==NULL)
		return true;

	if(T1==NULL || T1->data!=T2->data)
		return false;

	// T1 and T2 are not NULL
	return isMatch(T1->left,T2->left) && isMatch(T1->right,T2->right);
}

bool isSubTree( Node* T1, Node* T2 )
{
	if( isMatch(T1,T2) )
		return true;

	if( T1==NULL )
		return false;

	return isSubTree(T1->left,T2) || isSubTree(T1->right,T2);
}


