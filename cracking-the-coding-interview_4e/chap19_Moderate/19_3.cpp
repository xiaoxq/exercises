/*
 * 19_3.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

int numZerosOfNFactorial(const unsigned int n)
{
	int num = 0;
	int numForPower5 = n/5;

	while( numForPower5>0 )
	{
		num += numForPower5; // n/5, n/25, n/125, ...
		numForPower5 /= 5;
	}

	return num;
}
