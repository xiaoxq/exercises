/*
 * 5_7.cpp
 *
 *  Created on: 2013-4-29
 *      Author: beet
 */

#include <list>
using namespace std;

struct Element
{
	int getBitJ( int j )
	{
		return (data>>j) & 0x1;
	}

	int data;
};

int findMissingNumber( Element* array, int n )
{
	int result = 0;
	list<Element> toSearch;
	toSearch.assign( array, array+n );

	for( int bitPos=0; toSearch.size()>0; ++bitPos )
	{
		int ones = 0;
		for(list<Element>::iterator it=toSearch.begin(); it!=toSearch.end(); ++it)
			if(it->getBitJ(bitPos))
				++ones;

		bool missingOne = (ones*2)<toSearch.size();

		// set result
		if(missingOne)
			result |= 1<<bitPos;

		// reduce search space
		for(list<Element>::iterator it=toSearch.begin(); it!=toSearch.end();)
		{
			if( it->getBitJ(bitPos) ^ missingOne )
				toSearch.erase(it++);
			else
				++it;
		}
	}

	return result;
}

///////////////// TEST /////////////////
#include <stdio.h>
void test( Element* array, int n )
{
	printf( "findMissingNumber({" );
	for( int i=0; i<n; ++i )
		printf("%d,", array[i].data);
	printf( "} = %d\n", findMissingNumber(array,n) );
}
int main()
{
	Element test_case[] = {0,1,3,4};
	test( test_case, 1 ); // 1
	test( test_case, 2 ); // 2
	test( test_case, 3 ); // 2
	test( test_case, 4 ); // 2
	test( test_case+1, 1 ); // 0
}
