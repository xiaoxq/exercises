/*
 * Problem: http://leetcode.com/onlinejudge#question_37
 */

#include <vector>
#include <map>
#include <set>
using namespace std;

const int BoardSize = 9;
const string ALL_CANDI = "123456789";

class Solution
{
public:
	void solveSudoku(vector<vector<char> > &board)
	{
		decide( board, 0, 0 );
	}
private:
	bool decide(vector<vector<char> > &board, int row, int col)
	{
		while( row<BoardSize && board[row][col]!='.' )
		{
			if( ++col == BoardSize )
			{
				col = 0;
				++ row;
			}
		}
		if( row==BoardSize )
			return true;

		for( string::const_iterator it=ALL_CANDI.begin(); it!=ALL_CANDI.end(); ++it )
		{
			if( !checkPlacing( board, row, col, *it ) )
				continue;

			board[row][col] = *it;
			// try the remain
			int nextCol = col+1, nextRow = row;
			if( nextCol==BoardSize )
			{
				nextCol = 0;
				++nextRow;
			}
			if( decide(board, nextRow, nextCol) )
				return true;
		}
		board[row][col] = '.';
		return false;
	}

	// check if candidate can be placed at board[row][col]
	bool checkPlacing( vector<vector<char> > &board, int row, int col, char candidate )
	{
		// actually, only those in the candi should be checked
		// check left
		for( int i=0; i<BoardSize; ++i )
			if( board[row][i] == candidate )
				return false;

		// check upper
		for( int i=0; i<BoardSize; ++i )
			if( board[i][col] == candidate )
				return false;

		// check 3x3's top area
		const int topLeftRow = row / 3 * 3;
		const int topLeftCol = col / 3 * 3;
		for( int i=topLeftRow; i<topLeftRow+3; ++i )
		{
			for( int j=topLeftCol; j<topLeftCol+3; ++j )
			{
				if( board[i][j] == candidate )
					return false;
			}
		}
		return true;
	}
};

class AnotherSolution
{
public:
	void solveSudoku(vector<vector<char> > &board)
	{
		// board[i][j] can choose from the candi[i*10+j]
		map<int,set<char> > candi;
		genCandi( board, candi );
		decide( board, candi.begin(), candi.end() );
	}
private:
	void genCandi( vector<vector<char> > &board, map<int,set<char> >& candi )
	{
		for( int row=0; row<BoardSize; ++row )
		{
			for( int col=0; col<BoardSize; ++col )
			{
				if( board[row][col]!='.' )
					continue;
				set<char> cur_candi( ALL_CANDI.begin(), ALL_CANDI.end() );
				// check row
				for( int i=0; i<BoardSize; ++i )
					cur_candi.erase( board[i][col] );
				// check col
				for( int i=0; i<BoardSize; ++i )
					cur_candi.erase( board[row][i] );
				// check 3x3
				int rowLimit = row / 3 * 3 + 3;
				int colLimit = col / 3 * 3 + 3;
				for( int i=rowLimit-3; i<rowLimit; ++i )
				{
					for( int j=colLimit-3; j<colLimit; ++j )
						cur_candi.erase( board[i][j] );
				}
				candi.insert( make_pair(row*10+col, cur_candi) );
			}
		}
	}

	//
	bool decide( vector<vector<char> > &board,
			map<int,set<char> >::iterator candiIter, map<int,set<char> >::const_iterator end )
	{
		int index = candiIter->first;
		int row = index/10, col = index%10;
		// decide which candidate to use
		const set<char>& candidates = candiIter->second;
		++candiIter;

		for( set<char>::const_iterator it=candidates.begin(); it!=candidates.end(); ++it )
		{
			if( !checkPlacing( board, row, col, *it ) )
				continue;
			// try the remain
			board[row][col] = *it;
			if( candiIter==end )
				return true;
			if( decide(board, candiIter, end) )
				return true;
		}
		return false;
	}

	// check if candidate can be placed at board[row][col]
	bool checkPlacing( vector<vector<char> > &board, int row, int col, char candidate )
	{
		// actually, only those in the candi should be checked
		// check left
		for( int i=0; i<col; ++i )
			if( board[row][i] == candidate )
				return false;

		// check upper
		for( int i=0; i<row; ++i )
			if( board[i][col] == candidate )
				return false;

		// check 3x3's top area
		int topLeftRow = row / 3 * 3;
		int topLeftCol = col / 3 * 3;
		for( int i=topLeftRow; i<row; ++i )
		{
			for( int j=topLeftCol; j<topLeftCol+3; ++j )
			{
				if( board[i][j] == candidate )
					return false;
			}
		}
		return true;
	}
};
