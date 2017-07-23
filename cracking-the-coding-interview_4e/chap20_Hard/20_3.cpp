/*
 * 20_3.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

#include <stdlib.h>

// almost the same as 20_2
void randomlyGetMFromN( int* array, int n, int m )
{
	if( m>=n )
		return;

	for( int i=0; i<m; ++i )
	{
		// slot is i, range is [i,n)
		int index = rand() % (n-i) + i;
		// swap index and slot
		int temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	const int n = 100;
	const int m = 75;
	int array[n];
	int count[n] = {0};

	int rounds = 1000000;
	printf( "In %d rounds:\n", rounds );
	while(rounds--)
	{
		for(int i=0; i<n; ++i)
			array[i] = i;
		randomlyGetMFromN(array,n,m);
		for(int i=0; i<m; ++i)
			++count[ array[i] ];
	}

	for( int i=0; i<n; ++i )
		printf( "%d is selected %d times\n", i, count[i] );

	return 0;
}
