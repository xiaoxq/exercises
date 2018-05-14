/*
 * 12_3.cpp
 *
 *  Created on: 2013-5-15
 *      Author: beet
 */

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const unsigned int NumOfInt = 4 * 1000 * 1000 *1000;

int findAbsenceIn4BillionWith1GMemory( const char* filename )
{
	const unsigned int MemSize = 4 * 1024 * 1024 *1024;
	const unsigned int BitmapSize = NumOfInt / sizeof(char);

	ifstream fin( filename );
	// error
	if( !fin )
		return -1;

	char* bitmap = new char[ BitmapSize ];
	memset( bitmap, 0, BitmapSize );

	// mark all present bits
	int integer;
	while( fin>>integer )
	{
		int index = integer / 8;
		int offset = integer % 8;
		bitmap[index] |= (1<<offset);
	}
	fin.close();

	// find first absent bit
	for( int index=0; index<BitmapSize; ++index )
		for( int offset=0; offset<8; ++offset )
		{
			int bit = (bitmap[index] >> offset) & 0x1;
			if( bit )
				continue;
			delete[] bitmap;
			return (8*index + offset);
		}
	delete[] bitmap;

	// no result
	return -1;
}

int findAbsenceIn4BillionWith10MMemory( const char* filename )
{
	const unsigned int MemSize = 10 * 1024 *1024;
	// how many int32 can be stored in 10M memory
	const unsigned int BucketNum = MemSize / 4;
	const unsigned int BucketSize = NumOfInt / BucketNum;

	ifstream fin( filename );
	// error
	if( !fin )
		return -1;

	unsigned int* count = new unsigned int[BucketSize];
	memset( count, 0, sizeof(count) * sizeof(count[0]) );

	// mark all present bits
	int integer;
	while( fin>>integer )
		++count[ integer / BucketSize ];
	fin.close();

	int missingIntBlock = 0;
	while( missingIntBlock<BucketNum && count[missingIntBlock]==BucketSize )
		++missingIntBlock;
	delete[] count;

	// find the absence
	ifstream fin2( filename );
	// error
	if( !fin2 )
		return -1;

	// it can be stored in 10MB
	vector<int> container;
	// read in all integers in that set
	while( fin2>>integer )
		if( integer / BucketSize == missingIntBlock )
			container.push_back( integer );
	fin2.close();

	// two neighbors' difference should equal ModuleMask after sorting
	sort( container.begin(), container.end() );
	const int size = container.size();
	const int startVal = missingIntBlock * BucketSize;
	for( int i=0; i<size; ++i )
		if( container[i] != startVal + i )
			return startVal+i;

	// not found
	return -1;
}
