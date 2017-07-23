/*
 * 12_4.cpp
 *
 *  Created on: 2013-5-16
 *      Author: beet
 */

#include <vector>
using namespace std;

const int MaxiN = 32000;

void printDuplicateWith4KMemory( int* array, int size )
{
	char* bitset = new char[ MaxiN/8 ];
	memset( bitset, 0, MaxiN/8 );

	for( int i=0; i<size; ++i )
	{
		int charIndex = array[i] / 8;
		int bitIndex = array[i] % 8;

		// duplicate
		if( (bitset[charIndex]>>bitIndex) & 0x1 )
			printf( "%d\n", array[i] );
		else
			bitset[charIndex] |= 1<<bitIndex;
	}
	delete[] bitset;
	printf("========\n");
}

///////////////// TEST /////////////////
int main()
{
	int a[] = { 1,2,3,4,5,5,1 };

	printDuplicateWith4KMemory( a, 6 );
	printDuplicateWith4KMemory( a, 7 );

	return 0;
}
