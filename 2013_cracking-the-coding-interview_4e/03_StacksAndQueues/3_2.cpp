/*
 * 3_2.cpp
 *
 * push/pop/min: O(1)
 *
 *  Created on: 2013-4-12
 *      Author: beet
 */

#include <limits.h>
#include <iostream>
using namespace std;

// make it simple, or we should use template
typedef int Element;
const Element INVALID_ELEM = INT_MAX;

#ifndef NULL
#define NULL 0
#endif

struct Block
{
	Block(Element data, Block* next)
	{
		this->data = data;
		this->next = next;
		this->min = this;
	}
	Element data;
	Block* next;
	// point to the minimum block
	Block* min;
};

class Stack
{
private:
	Block* mTop;
public:
	Stack()
	{
		mTop = NULL;
	}

	void push(Element data)
	{
		Block* temp = new Block(data, mTop);
		if(mTop!=NULL && data > mTop->min->data)
			temp->min = mTop->min;
		mTop = temp;
	}

	void pop()
	{
		if(mTop!=NULL)
			mTop = mTop->next;
	}

	Element min()
	{
		if(mTop!=NULL)
			return mTop->min->data;
		return INVALID_ELEM;
	}

	// just for debugging
	void print()
	{
		cout << "[min=" << this->min() << "]";
		for( Block* i=mTop; i!=NULL; i=i->next )
			cout << i->data << " -> ";
		cout << "NULL" << endl;
	}
};

///////////////// TEST /////////////////
int main()
{
	Stack s;
	s.push(3); s.print();
	s.push(2); s.print();
	s.push(1); s.print();
	s.push(2); s.print();
	s.push(3); s.print();
	s.push(3); s.print();
	s.pop(); s.print();
	s.pop(); s.print();
	s.pop(); s.print();
	s.pop(); s.print();
	s.pop(); s.print();
	s.pop(); s.print();
	return 0;
}

