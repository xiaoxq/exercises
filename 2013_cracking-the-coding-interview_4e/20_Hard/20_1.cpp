/*
 * 20_1.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

int addWithNoArithm( int a, int b )
{
	if(b==0)
		return a;
	int sumWithoutCarry = a^b;
	int carries = (a&b) << 1;
	return addWithNoArithm(sumWithoutCarry, carries);
}
