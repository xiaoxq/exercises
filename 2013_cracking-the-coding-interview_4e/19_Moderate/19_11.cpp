/*
 * 19_11.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

#include <algorithm>
using namespace std;

void printAllPairsSumToX( int* array, int n, int x )
{
	sort( array, array+n );
	int left = 0, right = n-1;
	while( left<right )
	{
		int sum = array[left]+array[right];
		if( sum==x )
		{
			printf( "%d+%d=%d\n", array[left], array[right], x );
			++left;
			--right;
		}
		else if( sum<x )
			++left;
		else
			--right;
	}
}

///////////////// TEST /////////////////
// simplest test
int main()
{
	int array[] = { 7,6,4,5,3,2,1 };
	printAllPairsSumToX(array,7,8);
	return 0;
}
