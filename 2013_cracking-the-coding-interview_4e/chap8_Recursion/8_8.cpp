/*
 * 8_8.cpp
 *
 *  Created on: 2013-5-4
 *      Author: beet
 */

#include <stdio.h>
#include <vector>
using namespace std;

const int BoardWidth = 8;

void printXQueensSolutions( int row )
{
	static vector< vector<bool> > board;
	static vector<bool> marked_col;
	static vector<bool> marked_slash;
	static vector<bool> marked_backslash;

	// init
	if( row==0 )
	{
		board.assign( BoardWidth, vector<bool>( BoardWidth, false ) );
		marked_col.assign( BoardWidth, false );
		marked_slash.assign( BoardWidth*2-1, false );
		marked_backslash.assign( BoardWidth*2-1, false );
	}
	else if( row==BoardWidth )
	{
		// print one result
		for(int i=0; i<BoardWidth; ++i)
		{
			for(int j=0; j<BoardWidth; ++j)
				printf("%c ", board[i][j] ? '*' : 'o' );
			printf("\n" );
		}
		printf("=====================\n" );
		return;
	}

	for( int col=0; col<BoardWidth; ++col )
	{
		// look up forbidden areas
		if( marked_col[col] || marked_backslash[row+col] || marked_slash[BoardWidth-1+row-col] )
			continue;
		// mark, try, and revert
		board[row][col] = marked_col[col] = marked_backslash[row+col] = marked_slash[BoardWidth-1+row-col] = true;
		printXQueensSolutions(row+1);
		board[row][col] = marked_col[col] = marked_backslash[row+col] = marked_slash[BoardWidth-1+row-col] = false;
	}
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	printXQueensSolutions(0);
	return 0;
}
