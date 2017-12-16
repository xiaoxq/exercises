/*
 * 20_6.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

#include <stdlib.h>

void swap( int& a, int& b )
{
	int temp = a;
	a = b;
	b = temp;
}

void findTopMFromN( int* array, int n, int m )
{
	int pivot = rand() % n;

	int left=0, right=n-1;
	while( left<right )
	{
		while( array[left]>array[pivot] )
			++left;
		swap( array[left], array[pivot] );
		pivot = left++;

		while( array[right]<array[pivot] )
			--right;
		swap( array[pivot], array[right] );
		pivot = right;
	}

	++pivot;
	// get more
	if( pivot<m )
		findTopMFromN( array+pivot, n-pivot, m-pivot );
	// get less
	else if( pivot>m )
		findTopMFromN( array, pivot, m );
}

///////////////// TEST /////////////////
#include <stdio.h>

void test(int* array, int n, int m)
{
	printf("Top %d in array {", m);
	int* array_copy = new int[n];
	for( int i=0; i<n; ++i )
	{
		array_copy[i] = array[i];
		printf("%d, ", array[i]);
	}
	printf("} is {");

	findTopMFromN(array_copy,n,m);

	for( int i=0; i<m; ++i )
		printf("%d, ", array_copy[i]);
	printf("}\n");
}

int main()
{
	int array[] = { 1,3,5,7,9,2,4,6,8,10 };
	test(array,10,1);
	test(array,10,3);
	test(array,10,5);
	test(array,10,7);
	test(array,10,9);

	return 0;
}
