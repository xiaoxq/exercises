/*
 * 5_1.cpp
 *
 *  Created on: 2013-4-23
 *      Author: beet
 */

// simpler than the official solution
int fillMtoNbetweenIJ(int N, int M, int i, int j)
{
	// 1...11...10...0, which has i zeros
	int mask1 = (~0) << i;
	// 1...10...00...0, which has j+1 zeros
	int mask2 = (~0) << (j+1);
	// 1...10...01...1, from i to j(included) are zeros
	int mask = ~(mask1^mask2);

	return (N & mask) | (M << i);
}

