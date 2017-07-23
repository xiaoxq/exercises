/*
 * 8_7.cpp
 *
 *  Created on: 2013-5-3
 *      Author: beet
 */

const int CentValue[] = { 25, 10, 5, 1 };

int numberOfWaysToRepresenting( int cents, int CentValueIndex = 0 )
{
	if( cents<0 )
		return 0;
	if( CentValue[CentValueIndex]==1 )
		return 1;
	return numberOfWaysToRepresenting( cents-CentValue[CentValueIndex], CentValueIndex )
			+ numberOfWaysToRepresenting( cents, CentValueIndex+1 );
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int cents = 0;
	printf( "numberOfWaysToRepresenting(%d)=%d\n",
			cents, numberOfWaysToRepresenting(cents) ); //1
	cents = 1;
	printf( "numberOfWaysToRepresenting(%d)=%d\n",
			cents, numberOfWaysToRepresenting(cents) ); //1
	cents = 5;
	printf( "numberOfWaysToRepresenting(%d)=%d\n",
			cents, numberOfWaysToRepresenting(cents) ); //2
	cents = 9;
	printf( "numberOfWaysToRepresenting(%d)=%d\n",
			cents, numberOfWaysToRepresenting(cents) ); //2
	cents = 25;
	printf( "numberOfWaysToRepresenting(%d)=%d\n",
			cents, numberOfWaysToRepresenting(cents) ); //13
	return 0;
}
