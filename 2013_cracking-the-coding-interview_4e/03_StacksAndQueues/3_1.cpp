/*
 * 3_1.cpp
 *
 * construct: O(n)
 * push/pop/top: O(1)
 *
 *  Created on: 2013-4-2
 *      Author: beet
 *
 * It's just like OS's memory management
 */

#include <iostream>
using namespace std;

// make it simple, or we should use template
typedef int MemElement;
struct MemBlock
{
	MemBlock(MemElement* data, MemBlock* next)
	{
		this->data = data;
		this->next = next;
	}

	MemBlock( MemElement* data )
	{
		this->data = data;
		this->next = NULL;
	}
	MemElement* data;
	MemBlock* next;
};

class MultiStacks
{
private:
	int mStackNum;
	MemElement* mSingleArray;
	MemBlock** mStackTop;
	MemBlock* mFreeList;
public:
	MultiStacks(int memSize, int stackNum)
	{
		mStackNum = stackNum;
		mSingleArray = new MemElement[memSize];
		mStackTop = new MemBlock*[stackNum];

		// init stack tops
		for( int i=0; i<stackNum; ++i )
			mStackTop[i] = NULL;

		// init free blocks list
		MemBlock* next = NULL;
		for( int i=memSize-1; i>=0; --i )
		{
			MemBlock* temp = new MemBlock( mSingleArray+i, next );
			next = temp;
		}
		mFreeList = next;
	}

	~MultiStacks()
	{
		// delete blocks
		for( MemBlock* i=mFreeList; i!=NULL; )
		{
			MemBlock* next = i->next;
			delete i;
			i = next;
		}

		for( int i=0; i<mStackNum; ++i )
		{
			for( MemBlock* j=mStackTop[i]; j!=NULL; )
			{
				MemBlock* next = j->next;
				delete j;
				j = next;
			}
		}

		// delete containers
		delete[] mSingleArray;
		delete[] mStackTop;
	}

	void push( int stackIndex, MemElement data )
	{
		if(stackIndex>=mStackNum || mFreeList==NULL)
			return;

		// update free list
		MemBlock* temp = mFreeList;
		mFreeList = mFreeList->next;

		// update stack
		*(temp->data) = data;
		temp->next = mStackTop[stackIndex];
		mStackTop[stackIndex] = temp;
	}

	MemElement top( int stackIndex )
	{
		if(stackIndex>=mStackNum || mStackTop[stackIndex]==NULL)
			return -1;
		return *(mStackTop[stackIndex]->data);
	}

	void pop( int stackIndex )
	{
		if(stackIndex>=mStackNum || mStackTop[stackIndex]==NULL)
			return;

		// update stack
		MemBlock* temp = mStackTop[stackIndex];
		mStackTop[stackIndex] = mStackTop[stackIndex]->next;

		// update free list
		temp->next = mFreeList;
		mFreeList = temp;
	}

	// just for debugging
	void print()
	{
		cout << "FreeList: ";
		for( MemBlock* i=mFreeList; i!=NULL; i=i->next )
			cout << i->data - mSingleArray << " -> ";
		cout << "NULL" << endl;

		for( int i=0; i<mStackNum; ++i )
		{
			cout << "Stack " << i << ": ";
			for( MemBlock* j=mStackTop[i]; j!=NULL; j=j->next )
				cout << j->data - mSingleArray << "[" << *(j->data) << "] -> ";
			cout << "NULL" << endl;
		}
	}
};


///////////////// TEST /////////////////
int main()
{
	MultiStacks multiStack_9_3(9,3);
	multiStack_9_3.print();
	multiStack_9_3.push( 0, 1 );
	multiStack_9_3.push( 0, 2 );
	multiStack_9_3.push( 0, 3 );
	multiStack_9_3.push( 1, 4 );
	multiStack_9_3.push( 2, 5 );
	multiStack_9_3.print();
	multiStack_9_3.pop( 0 );
	multiStack_9_3.push( 1, 6 );
	multiStack_9_3.push( 1, 7 );
	multiStack_9_3.pop( 0 );
	multiStack_9_3.push( 2, 8 );
	multiStack_9_3.print();

	return 0;
}
