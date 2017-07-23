/*
 * 2_4.cpp
 *
 *  Created on: 2013-3-30
 *      Author: beet
 */

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	Node( int dat )
	{
		data = dat;
		next = NULL;
	}
	int data;
	Node* next;
};

Node* add( Node* head1, Node* head2 )
{
	Node* result = NULL;
	Node* tail = NULL;
	int carry = 0;

	while( head1!=NULL || head2!=NULL )
	{
		int num1 = (head1!=NULL) ? head1->data : 0;
		int num2 = (head2!=NULL) ? head2->data : 0;
		int sum = num1 + num2 + carry;
		carry = sum/10;
		sum %= 10;

		if( tail==NULL ) // initial
		{
			result = new Node( sum );
			tail = result;
		} else { // generally
			tail->next = new Node( sum );
			tail = tail->next;
		}

		if(head1!=NULL)
			head1 = head1->next;
		if(head2!=NULL)
			head2 = head2->next;
	}

	// the final carry
	if( carry>0 )
		tail->next = new Node( carry );

	return result;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;

void printList( Node* head )
{
	cout << "(";
	for( Node* it=head; it!=NULL; it=it->next )
		cout << it->data << "->";
	cout << "END)";
}

void test( Node* head1, Node* head2 )
{
	printList(head1);
	cout << " + ";
	printList(head2);
	cout << " = ";
	printList( add(head1,head2) );
	cout << endl;
}

int main()
{
	Node* test_list0 = new Node( 2 );
	Node* test_list1 = new Node( 5 );
	Node* test_list2 = new Node( 7 );
	Node* test_list3[] = { new Node(3), new Node(4), new Node(9) };
	test_list3[0]->next = test_list3[1];
	test_list3[1]->next = test_list3[2];

	Node* test_list4[] = { new Node(5), new Node(5), new Node(3) };
	test_list4[0]->next = test_list4[1];
	test_list4[1]->next = test_list4[2];

	Node* test_list5[] = { new Node(9), new Node(8), new Node(7), new Node(6) };
	test_list5[0]->next = test_list5[1];
	test_list5[1]->next = test_list5[2];
	test_list5[2]->next = test_list5[3];

	test(test_list0,test_list1);
	test(test_list1,test_list2);
	test(test_list3[0],test_list4[0]);
	test(test_list3[0],test_list5[0]);

	for(int i=sizeof(test_list3)/sizeof(test_list3[0])-1; i>=0; --i)
		delete test_list3[i];
	for(int i=sizeof(test_list4)/sizeof(test_list4[0])-1; i>=0; --i)
		delete test_list4[i];
	for(int i=sizeof(test_list5)/sizeof(test_list5[0])-1; i>=0; --i)
		delete test_list5[i];
	return 0;
}
