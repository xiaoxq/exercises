/*
 * 2_2.cpp O(n)
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

Node* getNthFromTail( Node* head, int n )
{
	Node* tail = head;
	while( n-- )
		tail = tail->next;
	while( tail )
	{
		head = head->next;
		tail = tail->next;
	}

	return head;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;

void test( Node* head, int n )
{
	cout << "getNthFromTail( ";
	for( Node* node=head; node!=NULL; node=node->next )
		cout << node->data << "->";
	cout << "NULL, " << n << " )= ";
	Node* node = getNthFromTail(head, n);
	cout << (node!=NULL ? node->data : -1 ) << endl;
}

int main()
{
	test(NULL, 1);

	Node* test_case0 = new Node( 0, NULL );
	test( test_case0, 0 );
	test( test_case0, 1 );
	delete test_case0;

	Node* test_case1[3];
	test_case1[2] = new Node( 2, NULL );
	test_case1[1] = new Node( 1, test_case1[2] );
	test_case1[0] = new Node( 0, test_case1[1] );
	test(test_case1[0], 0);
	test(test_case1[0], 1);
	test(test_case1[0], 2);
	test(test_case1[0], 3);
	delete test_case1[0];
	delete test_case1[1];
	delete test_case1[2];

	return 0;
}
