/*
 * 10_7.cpp
 *
 *  Created on: 2013-5-8
 *      Author: beet
 */

#include <queue>
#include <algorithm>
using namespace std;

int kth357( int k )
{
	if( k<=1 )
		return 1;

	queue<int> q3; // stores 3+
	queue<int> q35; // stores 3*5+
	queue<int> q357; // stores 3*5*7+

	// init
	q3.push( 3 );
	q35.push( 5 );
	q357.push( 7 );

	// notice: only k-1 loops, because we start from the second result, as the first is 1
	int min_val;
	while( --k )
	{
		min_val = min( min( q3.front(), q35.front() ), q357.front() );
		if( min_val == q3.front() ) // val3 is the minimum
		{
			q3.pop();
			q3.push( min_val * 3 );
			q35.push( min_val * 5 );
			q357.push( min_val * 7 );
		}
		else if( min_val == q35.front() ) // val35 is the minimum
		{
			q35.pop();
			q35.push( min_val * 5 );
			q357.push( min_val * 7 );
		}
		else // val357 is the minimum
		{
			q357.pop();
			q357.push( min_val * 7 );
		}
	}
	return min_val;
}

///////////////// TEST /////////////////
#include <stdio.h>

int main()
{
	printf("The %dth number of 3,5,7 is %d\n", 3, kth357(3) ); //5
	printf("The %dth number of 3,5,7 is %d\n", 7, kth357(7) ); //21
	printf("The %dth number of 3,5,7 is %d\n", 13, kth357(13) ); //63
	return 0;
}
