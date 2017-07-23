/*
 * 9_1.cpp
 *
 *  Created on: 2013-5-4
 *      Author: beet
 */

// A has enough buffer to hold A and B
void mergeFromTail( int* A, int lenA, int* B, int lenB )
{
	int last = lenA + lenB - 1;
	--lenA;
	--lenB;

	while( lenA>=0 && lenB>=0 )
		A[last--] = A[lenA]>=B[lenB] ? A[lenA--] : B[lenB--];
	while( lenB>=0 )
		A[last--] = B[lenB--];
}

