/*
 * Problem: http://leetcode.com/onlinejudge#question_63
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
	{
		if( obstacleGrid.empty() || obstacleGrid[0].empty() )
			return 0;

		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();

		// bad start or end
		if( obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1 )
			return 0;

		vector< vector<int> > pathNum( m, vector<int>(n, 0) );
		pathNum[m-1][n-1] = 1;

		for( int i=m-1; i>=0; --i )
		{
			for( int j=n-1; j>=0; --j )
			{
				// cannot pass
				if( obstacleGrid[i][j]==1 )
					continue;

				if( i+1 < m )
					pathNum[i][j] += pathNum[i+1][j];
				if( j+1 < n )
					pathNum[i][j] += pathNum[i][j+1];
			}
		}
		return pathNum[0][0];
	}
};
