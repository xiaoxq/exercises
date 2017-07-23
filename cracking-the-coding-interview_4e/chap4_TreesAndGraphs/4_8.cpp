/*
 * 4_8.cpp
 *
 *  Created on: 2013-4-21
 *      Author: beet
 */

#include <stack>
#include <stdio.h>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node* left;
	Node* right;
	int data;
};

void findPathOfSum( Node* root, const int sum, vector<int>& path )
{
	if( root==NULL )
		return;

	path.push_back( root->data );
	int temp = 0;
	const int size = path.size();
	for( int i=size-1; i>=0; --i )
	{
		temp += path[i];
		// find a path
		if( temp == sum )
		{
			printf( "%d", path[i] );
			for( int j=i+1; j<size; ++j )
				printf( " + %d", path[j] );
			printf( " = %d", sum );
		}
	}

	findPathOfSum( root->left, sum, path );
	findPathOfSum( root->right, sum, path );
	path.pop_back();
}
