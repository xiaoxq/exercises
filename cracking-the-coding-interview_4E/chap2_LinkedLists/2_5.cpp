/*
 * 2_5.cpp
 *
 *  Created on: 2013-4-2
 *      Author: beet
 *
 * It's really difficult...
 */

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node()
	{
		next = NULL;
	}
	Node* next;
};

Node* findBeginningOfLoop( Node* head )
{
	Node* h1 = head;
	Node* h2 = head;

	// h1 is always safe because it's behind h2
	// The solution in the book doesn't check h2, it's a bug
	while( h2!=NULL && h2->next!=NULL )
	{
		h1 = h1->next;
		h2 = h2->next->next;
		if( h1==h2 )
			break;
	}
	// reach the tail and no loop was found
	if( h2==NULL || h2->next==NULL )
		return NULL;

	h1 = head;
	while( h1!=h2 )
	{
		h1 = h1->next;
		h2 = h2->next;
	}

	return h1;
}

///////////////// TEST /////////////////
#include <iostream>
#include <map>
using namespace std;

map<unsigned int, char> addrHasShownUp;
void printList( Node* head )
{
	char count = 'A';

	cout << "(";
	for( Node* it=head; it!=NULL; it=it->next )
	{
		unsigned int addr = (unsigned int)&(*it);
		map<unsigned int, char>::iterator showup = addrHasShownUp.find( addr );
		// has shown up
		if( showup != addrHasShownUp.end() )
		{
			cout << showup->second;
			break;
		}
		// never showup
		cout << count << "->";
		addrHasShownUp.insert( pair<unsigned int, char>( addr, count ) );
		++count;
	}
	cout << ")";
}

void test( Node* head )
{
	addrHasShownUp.clear();

	cout << "findBeginningOfLoop";
	printList(head);
	cout << " = ";

	Node* node = findBeginningOfLoop(head);
	if( node==NULL )
		cout << "NULL";
	else
	{
		map<unsigned int, char>::iterator it = addrHasShownUp.find( (unsigned int)node );
		cout << it->second;
	}
	cout << endl;
}

int main()
{
	// NULL list
	Node* test_list0 = NULL;
	// 1 node list without loop
	Node test_list1;
	// 1 node list with loop
	Node test_list2;
	test_list2.next = &test_list2;
	// 2 nodes list without loop
	Node test_list3[2];
	test_list3[0].next = test_list3+1;
	// 2 nodes list with loop
	Node test_list4[2];
	test_list4[0].next = test_list4+1;
	test_list4[1].next = test_list4;
	// multi nodes list with loop
	Node test_list5[4];
	test_list5[0].next = test_list5+1;
	test_list5[1].next = test_list5+2;
	test_list5[2].next = test_list5+3;
	test_list5[3].next = test_list5+1;

	test(test_list0);
	test(&test_list1);
	test(&test_list2);
	test(test_list3);
	test(test_list4);
	test(test_list5);

	return 0;
}
