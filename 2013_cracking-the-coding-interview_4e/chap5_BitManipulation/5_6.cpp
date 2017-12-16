/*
 * 5_6.cpp
 *
 *  Created on: 2013-4-28
 *      Author: beet
 */

uint32_t swapEvenAndOddBits(uint32_t source)
{
	return ((source<<1)&0xaaaaaaaa) | ((source>>1)&0x55555555);
}
