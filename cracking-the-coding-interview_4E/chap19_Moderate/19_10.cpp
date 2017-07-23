/*
 * 19_10.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

// supplied by system
#include <stdlib.h>
int rand5()
{
	return rand() % 5;
}

// generate one bit by rand5
int rand2()
{
	// 0,1,2,3,4
	int ret = rand5();
	// ignore 2
	while(ret==2)
		ret = rand5();

	return (ret<2) ? 0 : 1;
}

// generate every bits by rand2
int rand7()
{
	int ret = 0;
	const int bitNumOf7 = 3;
	for( int i=0; i<bitNumOf7; ++i )
		ret |= rand2() << i;
	return ret;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int count[7] = {0,0,0,0,0,0,0};
	int rounds = 1000000;
	printf( "In %d rounds:\n", rounds );
	while(rounds--)
		++ count[ rand7() ];
	for( int i=0; i<7; ++i )
		printf( "%d shows up %d times\n", i, count[i] );

	return 0;
}
