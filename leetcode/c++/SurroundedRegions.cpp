/*
 * Problem: http://leetcode.com/onlinejudge#question_130
 */

#include <vector>
#include <queue>
using namespace std;

struct Pos
{
	int x,y;
	Pos( int i, int j )
	{
		x = i;
		y = j;
	}
};

class Solution
{
public:
	void solve(vector<vector<char> > &board)
	{
		if( board.empty() || board[0].empty() )
			return;
		const int m = board.size();
		const int n = board[0].size();

		for( int j=0; j<n; ++j )
		{
			// save from top row
			if( board[0][j]=='O' )
				save( board, 0, j );
			// save from bottom row
			if( board[m-1][j]=='O' )
				save( board, m-1, j );
		}
		for( int i=1; i<m-1; ++i )
		{
			// save from top row
			if( board[i][0]=='O' )
				save( board, i, 0 );
			// save from bottom row
			if( board[i][n-1]=='O' )
				save( board, i, n-1 );
		}
		for( int i=0; i<m; ++i )
		{
			for( int j=0; j<n; ++j )
			{
				if( board[i][j]=='S' )
					board[i][j] = 'O';
				else if( board[i][j]=='O' )
					board[i][j] = 'X';
			}
		}
	}
private:
	void save( vector<vector<char> >& board, int i, int j )
	{
		const int m = board.size();
		const int n = board[0].size();

		board[i][j] = 'S';
		queue<Pos> toSave;
		toSave.push( Pos(i,j) );
		while( !toSave.empty() )
		{
			i = toSave.front().x;
			j = toSave.front().y;
			toSave.pop();

			if( i>0 && board[i-1][j]=='O' )
			{
				board[i-1][j] = 'S';
				toSave.push( Pos(i-1,j) );
			}
			if( j>0 && board[i][j-1]=='O' )
			{
				board[i][j-1] = 'S';
				toSave.push( Pos(i,j-1) );
			}
			if( i+1<m && board[i+1][j]=='O' )
			{
				board[i+1][j] = 'S';
				toSave.push( Pos(i+1,j) );
			}
			if( j+1<n && board[i][j+1]=='O' )
			{
				board[i][j+1] = 'S';
				toSave.push( Pos(i,j+1) );
			}
		}
	}
};
