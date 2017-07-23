/*
 * Problem: http://leetcode.com/onlinejudge#question_52
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		// (x,y) will occupy colMark[y]
		vector<bool> colMark( n, false );
		// (x,y) will occupy upLeftMark[n-1+x-y]
		vector<bool> upLeftMark( 2*n-1, false );
		// (x,y) will occupy upLeftMark[x+y]
		vector<bool> upRightMark( 2*n-1, false );

		return tryPlace( n, 0, colMark, upLeftMark, upRightMark );
	}
private:
	int tryPlace(int n, int curRow, vector<bool>& colMark, vector<bool>& upLeftMark, vector<bool>& upRightMark)
	{
		// reach the end
		if( curRow==n )
			return 1;

		int result = 0;
		// try every col[j]
		for( int j=0; j<n; ++j )
		{
			if( colMark[j] || upLeftMark[n-1+curRow-j] || upRightMark[curRow+j] )
				continue;
			// find a slot here
			colMark[j] = upLeftMark[n-1+curRow-j] = upRightMark[curRow+j] = true;
			result += tryPlace( n, curRow+1, colMark, upLeftMark, upRightMark );
			colMark[j] = upLeftMark[n-1+curRow-j] = upRightMark[curRow+j] = false;
		}
		return result;
	}
};

class AnotherSolution
{
public:
	// not recursive
	int totalNQueens(int n)
	{
		// (x,y) will occupy colMark[y]
		vector<bool> colMark( n, false );
		// (x,y) will occupy upLeftMark[n-1+x-y]
		vector<bool> upLeftMark( 2*n-1, false );
		// (x,y) will occupy upLeftMark[x+y]
		vector<bool> upRightMark( 2*n-1, false );

		int result = 0;

		// row == cols.size()
		vector<int> cols;
		int row=0;
		// try placing at row
		while( row>=0 )
		{
			// find a solution
			if( row==n )
			{
				++result;
				--row;
				continue;
			}
			// get to a new row, init the previous col as -1
			if( row==cols.size() )
				cols.push_back( -1 );

			int& col = cols.back();
			if( col>=0 )
				colMark[ col ] = upLeftMark[n-1+row-col] = upRightMark[row+col] = false;

			for( ++col; col<n; ++col )
			{
				if( colMark[ col ] || upLeftMark[n-1+row-col] || upRightMark[row+col] )
					continue;
				break;
			}

			// cannot be placed at current row
			if( col == n )
			{
				cols.pop_back();
				--row;
			}
			else
			{
				colMark[ col ] = upLeftMark[n-1+row-col] = upRightMark[row+col] = true;
				++row;
			}
		}
		return result;
	}
};
