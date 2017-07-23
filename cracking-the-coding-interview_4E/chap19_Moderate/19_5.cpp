/*
 * 19_5.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

#include <stdio.h>
#include <algorithm>

enum BALL_COLOR
{
	R,
	Y,
	G,
	B
};

const int BallSlotNum = 4;
const int BallColorNum = 4;

void printGuessQuality( BALL_COLOR* solution, BALL_COLOR* guess )
{
	int solutionColorCount[] = {0,0,0,0};
	int guessColorCount[] = {0,0,0,0};
	int hit = 0, pseudoHit = 0;

	for( int i=0; i<BallSlotNum; ++i )
	{
		// mark hits
		if( solution[i]==guess[i] )
			++hit;
		// record others
		else
		{
			++solutionColorCount[ solution[i] ];
			++guessColorCount[ guess[i] ];
		}
	}
	// count pseudo hits
	for( int i=0; i<BallColorNum; ++i )
		pseudoHit += std::min( solutionColorCount[i], guessColorCount[i] );

	printf( "%d hits and %d pseudo hits\n", hit, pseudoHit );
}

///////////////// TEST /////////////////
int main()
{
	BALL_COLOR solution[] = {R,G,G,B};
	BALL_COLOR guess1[] = {Y,Y,Y,Y}; // 0 hits and 0 pseudo hits
	BALL_COLOR guess2[] = {Y,Y,Y,G}; // 0 hits and 1 pseudo hits
	BALL_COLOR guess3[] = {Y,Y,G,Y}; // 1 hits and 0 pseudo hits
	BALL_COLOR guess4[] = {Y,Y,G,R}; // 1 hits and 1 pseudo hits
	BALL_COLOR guess5[] = {Y,R,G,B}; // 2 hits and 1 pseudo hits
	BALL_COLOR guess6[] = {G,R,B,G}; // 0 hits and 4 pseudo hits
	BALL_COLOR guess7[] = {R,G,G,B}; // 4 hits and 0 pseudo hits
	printGuessQuality( solution, guess1 );
	printGuessQuality( solution, guess2 );
	printGuessQuality( solution, guess3 );
	printGuessQuality( solution, guess4 );
	printGuessQuality( solution, guess5 );
	printGuessQuality( solution, guess6 );
	printGuessQuality( solution, guess7 );
}
