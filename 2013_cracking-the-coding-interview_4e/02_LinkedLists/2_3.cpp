/*
 * 2_3.cpp O(n)
 *
 *  Created on: 2013-3-30
 *      Author: beet
 */

#ifndef NULL
#define NULL 0
#endif

struct Node
{
	int data;
	Node* next;
};

void deleteMe( Node* me )
{
	if( me==NULL || me->next==NULL )
		return;
	me->data = me->next->data;
	me->next = me->next->next;

	delete me->next;
}


