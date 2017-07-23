/*
 * 20_4.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

const int maxPowerOf10 = 15; // as 10^15 is big enough for an integer

// power = 10^i, 15>i>0
int count2sOf10sPower( int power )
{
	// record the already counted powers
	static int resultMap[maxPowerOf10] = { 0 };

	// not counted yet
	if( power>0 && resultMap[power]==0 )
	{
		// val = 10^(power-1)
		int val = 1;
		for( int i=1; i<power; ++i )
			val *= 10;

		resultMap[power] = val + 10 * count2sOf10sPower(power-1);
	}
	return resultMap[power];
}

int count2s( int n )
{
	if(n<=0)
		return 0;

	int power = 1;
	int val = 10;
	while( val<=n )
	{
		++power;
		val *= 10;
	}
	val /= 10;
	int head = n / val;
	int remain = n % val;

	// lower powers + remains in current power
	int ret = head * count2sOf10sPower(power-1) + count2s(remain);
	// add current power's heads
	if( head==2 )
		ret += remain+1;
	// add the whole heads of current power
	else if( head>2 )
		ret += val;

	return ret;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int n = 1;
	printf( "count2s(%d)=%d\n", n, count2s(n) ); // 0
	n = 6;
	printf( "count2s(%d)=%d\n", n, count2s(n) ); // 1
	n = 26;
	printf( "count2s(%d)=%d\n", n, count2s(n) ); // 10
	n = 126;
	printf( "count2s(%d)=%d\n", n, count2s(n) ); // 30

	// the following equations should be right, they are mentioned in the official solution
	// count2s(513) = 5 * count2s(99) + count2s(13) + 100;
	// count2s(279) = 2 * count2s(99) + count2s(79) + 79 + 1
	printf( "count2s(513) = %d\n", count2s(513) );
	printf( "5 * count2s(99) + count2s(13) + 100 = %d\n", 5 * count2s(99) + count2s(13) + 100 );
	printf( "count2s(279) = %d\n", count2s(279) );
	printf( "2 * count2s(99) + count2s(79) + 79 + 1 = %d\n", 2 * count2s(99) + count2s(79) + 79 + 1 );

	return 0;
}
