/*
 * Problem: http://leetcode.com/onlinejudge#question_51
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string> > solveNQueens(int n)
	{
		// board
		vector< vector<bool> > board( n, vector<bool>(n, false) );
		// (x,y) will occupy colMark[y]
		vector<bool> colMark( n, false );
		// (x,y) will occupy upLeftMark[n-1+x-y]
		vector<bool> upLeftMark( 2*n-1, false );
		// (x,y) will occupy upLeftMark[x+y]
		vector<bool> upRightMark( 2*n-1, false );

		vector<vector<string> > result;
		tryPlace( board, n, 0, result, colMark, upLeftMark, upRightMark );

		return result;
	}
private:
	void tryPlace( vector< vector<bool> >& board, int n, int curRow, vector<vector<string> >& result,
			vector<bool>& colMark, vector<bool>& upLeftMark, vector<bool>& upRightMark)
	{
		// reach the end, record
		if( curRow==n )
		{
			vector<string> solution;
			for( int i=0; i<n; ++i )
			{
				string row( n, '.' );
				for( int j=0; j<n; ++j )
				{
					if( board[i][j] )
						row[j] = 'Q';
				}
				solution.push_back( row );
			}
			result.push_back( solution );
			return;
		}

		// try every col[j]
		for( int j=0; j<n; ++j )
		{
			if( colMark[j] || upLeftMark[n-1+curRow-j] || upRightMark[curRow+j] )
				continue;
			// find a slot here
			board[curRow][j] = colMark[j] = upLeftMark[n-1+curRow-j] = upRightMark[curRow+j] = true;
			tryPlace( board, n, curRow+1, result, colMark, upLeftMark, upRightMark );
			board[curRow][j] = colMark[j] = upLeftMark[n-1+curRow-j] = upRightMark[curRow+j] = false;
		}
	}
};
