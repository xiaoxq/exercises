/*
 * Problem: http://leetcode.com/onlinejudge#question_85
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int maximalRectangle(vector<vector<char> > &matrix)
	{
		if( matrix.empty() || matrix[0].empty() )
			return 0;

		const int m=matrix.size();
		const int n=matrix[0].size();

		// onesAtLeft stores how many 1s is at left
		vector<vector<int> > onesAtLeft( m, vector<int>(n, 0) );
		for( int i=0; i<m; ++i )
			onesAtLeft[i][0] = matrix[i][0] - '0';
		for( int i=0; i<m; ++i )
		{
			for( int j=1; j<n; ++j )
				onesAtLeft[i][j] = ( matrix[i][j]=='0' ) ? 0 : onesAtLeft[i][j-1]+1;
		}

		// for each position, count how many 1s is at upper-left rect
		int maxiSum = 0;
		for( int i=0; i<m; ++i )
		{
			for( int j=0; j<n; ++j )
			{
				int width = onesAtLeft[i][j];
				for( int height=1; height<=i+1; ++height )
				{
					width = min( width, onesAtLeft[i-height+1][j] );
					if( width==0 )
						break;
					maxiSum = max( maxiSum, width * height );
				}
			}
		}
		return maxiSum;
	}
};
