/*
 * Problem: http://leetcode.com/onlinejudge#question_120
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTotal(vector<vector<int> > &triangle)
	{
		if( triangle.empty() )
			return 0;

		const int size = triangle.size();
		vector<int> lastLevel( size+1, 0 ), curLevel( size+1, 0 );

		for( int i=size-1; i>=0; --i )
		{
			for( int j=0; j<=i; ++j )
				curLevel[j] = triangle[i][j] + min( lastLevel[j], lastLevel[j+1] );
			curLevel.swap( lastLevel );
		}
		return lastLevel[0];
	}
};
