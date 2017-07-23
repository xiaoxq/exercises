/*
 * 16_5.cpp
 *
 *  Created on: 2013-5-17
 *      Author: beet
 */

enum ENDIAN
{
	BIG_ENDIAN,
	LITTLE_ENDIAN
};

union IntAndChar
{
	int i;
	char c[ sizeof(int) ];
};

ENDIAN getEndian()
{
	IntAndChar ic;
	ic.i = 0x1;

	return (ic.c[0]==1) ? LITTLE_ENDIAN : BIG_ENDIAN;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	printf( getEndian()==BIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN" );
	return 0;
}
