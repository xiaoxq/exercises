/*
 * Problem: http://leetcode.com/onlinejudge#question_62
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		// m x n, records pathes num from (i,j) to the right bottom
		vector< vector<int> > pathNum( m, vector<int>(n, 0) );
		pathNum[m-1][n-1] = 1;

		for( int i=m-1; i>=0; --i )
		{
			for( int j=n-1; j>=0; --j )
			{
				if( i < m-1 )
					pathNum[i][j] += pathNum[i+1][j];
				if( j < n-1 )
					pathNum[i][j] += pathNum[i][j+1];
			}
		}
		return pathNum[0][0];
	}
};
