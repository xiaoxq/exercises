/*
 * 20_11.cpp
 *
 *  Created on: 2013-6-2
 *      Author: beet
 */

enum Cell
{
	BLACK,
	WHITE
};

struct Subsquare
{
	int x, y;
	int size;
};

// according to the context, only check left/right/bottom border
bool checkBlackBorders( const Cell** square, const Subsquare& subsquare )
{
	int leftCol = subsquare.y;
	int rightCol = subsquare.y+subsquare.size-1;
	int bottomRow = subsquare.x+subsquare.size-1;

	// check left/right border: (topRow, bottomRow]
	for( int row=subsquare.x+1; row<=bottomRow; ++row )
		if( square[row][leftCol]==WHITE || square[row][rightCol]==WHITE )
			return false;

	// check bottom border: (leftCol,rightCol)
	for( int col=leftCol+1; col<rightCol; ++col )
		if( square[bottomRow][col]==WHITE )
			return false;

	return true;
}

Subsquare findMaxSquareWithBlackBorders( const Cell** square, const int size )
{
	Subsquare result;
	Subsquare temp;
	result.size = 0;
	for( int row=0; row + result.size < size; ++row )
	{
		for( int left=0; left+result.size <size; ++left )
		{
			if( square[row][left]==BLACK )
			{
				// find the right bound
				int right=left+1;
				while( right<size && square[row][right]==BLACK)
					++right;

				// [left,right) are all black, check if square exists
				temp.x = row;
				temp.y = left;
				for( int checkRight=right; left+result.size<checkRight; --checkRight )
				{
					temp.size = checkRight-left;
					if( checkBlackBorders( square, temp ) )
						result = temp;
				}

				left = right;
			}
		}
	}
	return result;
}
