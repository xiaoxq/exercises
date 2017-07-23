/*
 * 3_3.cpp
 *
 *  Created on: 2013-4-14
 *      Author: beet
 */

// make it simple, or we should use template
typedef int Element;

#ifndef NULL
#define NULL 0
#endif

const int StackCapacity = 3;

struct StackNode
{
	StackNode( int capacity, StackNode* next )
	{
		m_capacity = capacity;
		m_storage = new Element[capacity];
		this->next = next;
		m_write_pos = 0;
	}

	~StackNode() { delete[] m_storage; }
	bool isEmpty() { return (m_write_pos==m_capacity); }
	bool isFull() { return (m_write_pos==0); }
	void push( Element e ) { m_storage[m_write_pos++] = e; }
	void pop() { --m_write_pos; }

	int m_capacity;
	Element* m_storage;
	int m_write_pos;

	StackNode* next;
};

class SetOfStacks
{
private:
	StackNode* mStackHead;
	int mStackNodeNum;
public:
	SetOfStacks()
	{
		mStackHead = new StackNode(StackCapacity, NULL);
		mStackNodeNum = 1;
	}

	void push( Element e )
	{
		if( mStackHead->isFull() )
		{
			StackNode* newHead = new StackNode(StackCapacity, mStackHead);
			mStackHead = newHead;
			++mStackNodeNum;
		}
		mStackHead->push(e);
	}

	void pop()
	{
		if(!mStackHead->isEmpty())
			mStackHead->pop();
		if(mStackHead->isEmpty() && mStackHead->next!=NULL)
		{
			StackNode* newHead = mStackHead->next;
			delete mStackHead;
			mStackHead = newHead;
			--mStackNodeNum;
		}
	}

	void popAt( int index )
	{
		int reverseIndex = mStackNodeNum - 1 - index;

		StackNode* current = mStackHead;
		StackNode* previous = NULL;
		while( reverseIndex-- )
		{
			previous = current;
			current = current->next;
		}

		if(!current->isEmpty())
			current->pop();

		if(current->isEmpty())
		{
			// it's the head
			if(previous==NULL)
				mStackHead = current->next;
			// it's in middle
			else
				previous->next = current->next;

			delete current;
		}
	}
};
