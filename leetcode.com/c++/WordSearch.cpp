/*
 * Problem: http://leetcode.com/onlinejudge#question_79
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char> > &board, string word)
	{
		if( board.empty() || board[0].empty() )
			return false;

		int m=board.size(), n=board[0].size();

		for( int i=0; i<m; ++i )
		{
			for( int j=0; j<n; ++j )
			{
				if( startDeepSearch(board,i,j,word,0) )
					return true;
			}
		}
		return false;
	}
private:
	bool startDeepSearch(vector<vector<char> > &board, int i, int j,
			const string& word, int pos)
	{
		if( pos==word.length() )
			return true;
		if( i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[pos] )
			return false;

		const char c = board[i][j];
		board[i][j] = 0;
		if( startDeepSearch(board,i-1,j,word,pos+1)
				|| startDeepSearch(board,i+1,j,word,pos+1)
				|| startDeepSearch(board,i,j-1,word,pos+1)
				|| startDeepSearch(board,i,j+1,word,pos+1) )
			return true;
		board[i][j] = c;

		return false;
	}
};
