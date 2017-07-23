/*
 * 2_1.cpp O(n)
 *
 *  Created on: 2013-3-30
 *      Author: beet
 */

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node( int dat, Node* nxt )
	{
		data = dat;
		next = nxt;
	}
	int data;
	Node* next;
};

void uniq( Node* head )
{
	if( head==NULL )
		return;

	Node* tail = head;
	Node* curr = tail->next;

	while(curr!=NULL)
	{
		bool isUniq = true;
		Node* temp = head;
		while( true ) {
			if( temp->data == curr->data )
			{
				isUniq = false;
				break;
			}
			if( temp == tail )
				break;
			temp = temp->next;
		}

		if(isUniq)
		{
			tail->next = curr;
			tail = curr;
		}
		curr = curr->next;
	}
	tail->next = NULL;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;

void test( Node* head )
{
	cout << "uniq( ";
	for( Node* n=head; n!=NULL; n=n->next )
		cout << n->data << "->";
	cout << "NULL ) = ";

	uniq(head);

	for( Node* n=head; n!=NULL; n=n->next )
		cout << n->data << "->";
	cout << "NULL" << endl;
}

int main()
{
	test(NULL);

	Node* test_case0 = new Node( 0, NULL );
	test( test_case0 );
	delete test_case0;

	Node* test_case1[3];
	test_case1[2] = new Node( 2, NULL );
	test_case1[1] = new Node( 1, test_case1[2] );
	test_case1[0] = new Node( 0, test_case1[1] );
	test(test_case1[0]);
	delete test_case1[0];
	delete test_case1[1];
	delete test_case1[2];

	Node* test_case2[3];
	test_case2[2] = new Node( 1, NULL );
	test_case2[1] = new Node( 1, test_case2[2] );
	test_case2[0] = new Node( 0, test_case2[1] );
	test(test_case2[0]);
	delete test_case2[0];
	delete test_case2[1];
	delete test_case2[2];

	Node* test_case3[3];
	test_case3[2] = new Node( 0, NULL );
	test_case3[1] = new Node( 1, test_case3[2] );
	test_case3[0] = new Node( 0, test_case3[1] );
	test(test_case3[0]);
	delete test_case3[0];
	delete test_case3[1];
	delete test_case3[2];

	return 0;
}
