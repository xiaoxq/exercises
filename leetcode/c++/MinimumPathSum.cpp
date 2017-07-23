/*
 * Problem: http://leetcode.com/onlinejudge#question_64
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minPathSum(vector<vector<int> > &grid)
	{
		if( grid.empty() || grid[0].empty() )
			return 0;

		const int m = grid.size();
		const int n = grid[0].size();

		vector< vector<int> > pathNum( grid );
		for( int i=m-1; i>=0; --i )
		{
			for( int j=n-1; j>=0; --j )
			{
				// find mini way
				if( i<m-1 && j<n-1 )
					pathNum[i][j] += min(pathNum[i+1][j], pathNum[i][j+1]);
				else if( i<m-1 )
					pathNum[i][j] += pathNum[i+1][j];
				else if( j<n-1 )
					pathNum[i][j] += pathNum[i][j+1];
			}
		}

		return pathNum[0][0];
	}
};
