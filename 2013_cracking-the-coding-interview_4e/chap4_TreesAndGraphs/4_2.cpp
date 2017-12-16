/*
 * 4_2.cpp
 *
 * O(n)
 *
 *  Created on: 2013-4-18
 *      Author: beet
 */

#include<queue>
#include<vector>
#include<set>
using namespace std;

struct Node
{
	vector<Node*> OutGoing;
};

bool hasRoute( Node* A, Node* B )
{
	if(A==B)
		return true;

	queue<Node*> visiting;
	set<Node*> visited;
	visiting.push(A);
	visited.insert(A);

	while(!visiting.empty())
	{
		Node* current = visiting.front(); visiting.pop();

		for( vector<Node*>::iterator it=current->OutGoing.begin();
				it!=current->OutGoing.end(); ++it )
		{
			// reached
			if(*it==B)
				return true;

			// havn't visited
			if( visited.find(*it)==visited.end() )
			{
				visited.insert(*it);
				visiting.push(*it);
			}
		}
	}

	return false;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	Node A, B, C, D, E;
	A.OutGoing.push_back( &C );
	A.OutGoing.push_back( &D );
	C.OutGoing.push_back( &E );
	printf("%d\n", hasRoute(&A,&B)); // false
	E.OutGoing.push_back( &A );
	E.OutGoing.push_back( &D );
	printf("%d\n", hasRoute(&A,&B)); // false
	E.OutGoing.push_back( &B );
	printf("%d\n", hasRoute(&A,&B)); // true
	printf("%d\n", hasRoute(&E,&B)); // true
	A.OutGoing.push_back( &A );
	printf("%d\n", hasRoute(&A,&A)); // true

	return 0;
}
