/*
 * 19_7.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

#include <stdio.h>

// if all are negative, result will be empty sequence, whose sum is 0
void printLargestSumSequence( int* array, int n )
{
	int sum = 0, startPos = 0;
	int maxSum = 0, maxSumStartPos = 0;
	for( int i=0; i<n; ++i )
	{
		sum += array[i];
		if( sum>maxSum )
		{
			maxSum = sum;
			maxSumStartPos = startPos;
		}
		else if( sum<0 )
		{
			sum = 0;
			startPos = i+1;
		}
	}

	printf( "{" );
	while(maxSum>0)
	{
		printf( "%d, ", array[maxSumStartPos] );
		maxSum -= array[maxSumStartPos];
		++maxSumStartPos;
	}
	printf( "}\n" );
}

///////////////// TEST /////////////////
// only a simple test
int main()
{
	int array[] = {2, -8, 3, -2, 4, -10};
	printLargestSumSequence(array, 6); //{3,-2,4}
	return 0;
}
