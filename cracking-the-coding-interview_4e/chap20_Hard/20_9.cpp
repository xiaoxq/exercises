/*
 * 20_9.cpp
 *
 *  Created on: 2013-5-22
 *      Author: beet
 */

#include <queue>
using namespace std;

int putNumberGetMedian( int number )
{
	// maxHeap keeps the smaller half, and minHeap keeps the greater half
	static priority_queue< int, vector<int>, less<int> > maxHeap;
	static priority_queue< int, vector<int>, greater<int> > minHeap;

	// we make sure that maxHeap.size() - minHeap.size() = {0,1}
	if( minHeap.size() == maxHeap.size() )
	{
		if( maxHeap.empty() )
			maxHeap.push( number );
		else
		{
			// new number goes to smaller half
			if( number<=minHeap.top() )
				maxHeap.push( number );
			// new number goes to greater half
			else
			{
				maxHeap.push( minHeap.top() );
				minHeap.pop();
				minHeap.push(number);
			}
		}
	}
	else
	{
		// new number goes to greater half
		if( number>=maxHeap.top() )
			minHeap.push(number);
		// new number goes to smaller half
		else
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(number);
		}
	}
	return maxHeap.top();
}

///////////////// TEST /////////////////
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int random = rand() % 100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	random = rand()%100;
	printf( "putNumberGetMedian(%d)=%d\n", random, putNumberGetMedian(random) );
	return 0;
}
