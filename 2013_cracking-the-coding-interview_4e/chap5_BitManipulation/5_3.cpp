/*
 * 5_3.cpp
 *
 *  Created on: 2013-4-24
 *      Author: beet
 */

#include "stdio.h"

const int thirty_one1s = 0x7FFFFFFF;

// change first '01' to '10', and move all 1s to most right
void printNextSmallestNumberWithSame1s( int source )
{
	int previous = 0;
	int ones = 0;
	for( int i=0; i<sizeof(source)*8; ++i )
	{
		// 1...
		if( (source >> i) & 0x1 )
		{
			++ones;
			previous = 1;
		}
		// 01...
		else if( previous==1 )
		{
			// set the tail as 10*1{ones-1}
			unsigned int tail = (1<<i) | ( thirty_one1s >> (sizeof(source)*8-ones));
			// 1*0{i+1}
			int mask = thirty_one1s << (i+1);
			int result = (source & mask) | tail;
			printf("Next smallest number of %d is %d\n", source, result );
			return;
		}
		// else 00, just pass
	}
	// no '01' in the number, return itself
	printf("Next smallest number of %d is none\n", source);
}

// change first '10' to '01', and move all 0s to most right
void printNextLargestNumberWithSame1s( int source )
{
	int previous = 1;
	int zeros = 0;
	for( int i=0; i<sizeof(source)*8; ++i )
	{
		// 1...
		if( (source>>i) & 0x1 )
		{
			// 10...
			if( previous==0 )
			{
				// set the tail as 01{i-zeros+1}0{zeros-1}
				unsigned int tail = ( thirty_one1s >> (sizeof(source)*8-i+zeros-2) ) << (zeros-1);
				// 1*0{i+1}
				int mask = thirty_one1s << (i+1);
				int result = (source & mask) | tail;
				printf("Next largest number of %d is %d\n", source, result );
				return;
			}
		}
		// 0...
		else
		{
			previous = 0;
			++zeros;
		}
	}
	printf("Next largest number of %d is none\n", source);
}

///////////////// TEST /////////////////
int main()
{
	printNextSmallestNumberWithSame1s( 0 ); // 0 -> none
	printNextSmallestNumberWithSame1s( 1 ); // 01 -> 10
	printNextSmallestNumberWithSame1s( 2 ); // 010 -> 100
	printNextSmallestNumberWithSame1s( 3 ); // 011 -> 101
	printNextSmallestNumberWithSame1s( 0x24 ); // 10 0100 -> 101000
	printNextLargestNumberWithSame1s( 0 ); // 0 -> none
	printNextLargestNumberWithSame1s( 1 ); // 01 -> none
	printNextLargestNumberWithSame1s( 2 ); // 10 -> 01
	printNextLargestNumberWithSame1s( 3 ); // 011 -> none
	printNextLargestNumberWithSame1s( 0x19 ); // 1 1001 -> 10110
	printNextLargestNumberWithSame1s( 0x163 ); // 1 0110 0011 -> 1 0101 1100(348)
}
