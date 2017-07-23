/*
 * 10_4.cpp
 *
 *  Created on: 2013-5-7
 *      Author: beet
 */

int minus( int a, int b )
{
	return a + ~b + 1;
}

// '-' can be done by minus()
int times( int a, int b )
{
	bool neg = b < 0;
	if(neg)
		b = -b;

	int result = 0;
	while( b-- )
		result += a;

	if( neg )
		result = -result;

	return result;
}

#include <limits.h>
// '-' can be done by minus()
int divide( int a, int b )
{
	// invalid
	if(b==0)
		return INT_MAX;

	bool neg = a<0;
	if( neg )
		a = -a;

	if( b<0 )
	{
		b = -b;
		neg = !neg;
	}

	int result = 0;
	while( a>=b )
	{
		++result;
		a -= b;
	}
	if(neg)
		result = -result;
	return result;
}

///////////////// TEST /////////////////
#include <stdio.h>

void test( int a, int b )
{
	printf( "minus(%d,%d)=%d\n",a,b,minus(a,b) );
	printf( "times(%d,%d)=%d\n",a,b,times(a,b) );
	printf( "divide(%d,%d)=%d\n",a,b,divide(a,b) );
}

int main()
{
	test(0,0);
	test(0,7);
	test(7,0);
	test(0,-3);
	test(-3,0);
	test(99,11);
	test(-9,-11);
	test(-9,7);
	test(9,-7);

	return 0;
}
