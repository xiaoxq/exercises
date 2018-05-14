/*
 * 19_1.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

void swap1( int& a, int& b )
{
	a += b; // may overflow
	b = a-b;
	a = a-b;
}

void swap2( int& a, int& b )
{
	a ^= b;
	b = a^b;
	a = a^b;
}
