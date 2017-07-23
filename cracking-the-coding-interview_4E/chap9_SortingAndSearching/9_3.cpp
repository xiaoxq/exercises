/*
 * 9_3.cpp
 *
 *  Created on: 2013-5-5
 *      Author: beet
 */

int binarySearchInRotatedArray( int* array, int left, int right, int target )
{
	while( left+1<right )
	{
		int middle = (left+right)/2;

		if( array[left]<array[middle] )
			(target>=array[left] && target<array[middle]) ? right=middle : left=middle;
		else
			(target >= array[middle] && target<=array[right-1]) ? left=middle : right=middle;
	}
	// found or not
	if( array[left]==target )
		return left;
	return -1;
}

///////////////// TEST /////////////////
#include <iostream>
int main()
{
	int array[] = { 4,5,6,7,8,9,0,1,2,3 };
	int target = 0;
	printf( "binarySearchInRotatedArray(%d)=%d\n",
			target, binarySearchInRotatedArray(array,0,10,target) ); //6
	target = 1;
	printf( "binarySearchInRotatedArray(%d)=%d\n",
			target, binarySearchInRotatedArray(array,0,10,target) ); //7
	target = 3;
	printf( "binarySearchInRotatedArray(%d)=%d\n",
			target, binarySearchInRotatedArray(array,0,10,target) ); //9
	target = 4;
	printf( "binarySearchInRotatedArray(%d)=%d\n",
			target, binarySearchInRotatedArray(array,0,10,target) ); //0
	target = 7;
	printf( "binarySearchInRotatedArray(%d)=%d\n",
			target, binarySearchInRotatedArray(array,0,10,target) ); //3
	target = 9;
	printf( "binarySearchInRotatedArray(%d)=%d\n",
			target, binarySearchInRotatedArray(array,0,10,target) ); //5
	return 0;
}
