/*
 * 19_4.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

int max(int a, int b)
{
	// factor = (a>b) ? 0 : -1;
	int factor = (a-b) >> ( sizeof(int)*8 - 1 );
	return a + (a-b) * factor;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int a=0, b=0;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=0, b=-5;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=-6, b=0;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=0, b=5;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=6, b=0;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=-6, b=-5;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=5, b=6;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=6, b=-5;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );
	a=-6, b=5;
	printf("max(%d,%d)=%d\n",a,b,max(a,b) );

	return 0;
}
