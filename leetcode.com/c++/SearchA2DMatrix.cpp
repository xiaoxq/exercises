/*
 * Problem: http://leetcode.com/onlinejudge#question_74
 */

#include <vector>
using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		if( matrix.empty() || matrix[0].empty() )
			return false;

		const int m = matrix.size();
		const int n = matrix[0].size();

		// search at first col
		for( int x=0, y=n-1; x<m && y>=0; )
		{
			if( matrix[x][y]==target )
				return true;

			( matrix[x][y]<target ) ? ++x : --y;
		}
		return false;
	}
};
