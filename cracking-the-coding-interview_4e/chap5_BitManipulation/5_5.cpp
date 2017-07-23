/*
 * 5_5.cpp
 *
 *  Created on: 2013-4-28
 *      Author: beet
 */

unsigned int bitsToConvert( int from, int to )
{
	unsigned int result = 0;
	unsigned int diff = from ^ to;

	for( int i=0; i<sizeof(diff)*8; ++i )
		result += (diff>>i) & 0x1;
	return result;
}
