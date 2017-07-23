/*
 * 8_1.cpp
 *
 *  Created on: 2013-4-30
 *      Author: beet
 */

// Recursive
unsigned int nthFibonacci( const unsigned int n )
{
	if( n<2 )
		return n; // f(0)=0, f(1)=1
	return nthFibonacci(n-1) + nthFibonacci(n-2);
}

// Non recursive
unsigned int nthFibonacci2( const unsigned int n )
{
	if( n<2 )
		return n; // f(0)=0, f(1)=1
	unsigned int i_1 = 0, i_2 = 1;
	for( unsigned int i=2; i<=n; ++i )
	{
		unsigned int ithFibonacci = i_2 + i_1;
		i_2 = i_1;
		i_1 = ithFibonacci;
	}
	return i_1;
}
