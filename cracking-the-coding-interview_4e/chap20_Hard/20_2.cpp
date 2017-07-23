/*
 * 20_2.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

#include <stdlib.h>

const int CardNum = 52;
void shuffle( int cards[CardNum] )
{
	for( int i=CardNum; i>1; --i )
	{
		int slot = i-1;
		int index = rand() % i;
		// swap index and slot
		int temp = cards[slot];
		cards[slot] = cards[index];
		cards[index] = temp;
	}
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int cards[CardNum];
	int count[CardNum] = {0};
	const int countPos = 10;

	int rounds = 1000000;
	printf( "In %d rounds:\n", rounds );
	while(rounds--)
	{
		for(int i=0; i<CardNum; ++i)
			cards[i] = i;
		shuffle(cards);
		++count[ cards[countPos] ];
	}
	for( int i=0; i<CardNum; ++i )
		printf( "Card %d shows up %d times at position %d\n", i, count[i], countPos );

	return 0;
}
