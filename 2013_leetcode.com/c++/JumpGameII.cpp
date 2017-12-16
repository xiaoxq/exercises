/*
 * Problem: http://leetcode.com/onlinejudge#question_45
 */

#include <algorithm>
using namespace std;

class Solution
{
public:
	int jump(int A[], int n)
	{
		if( n==1 )
			return 0;
		// reach lBound in result jumps, reach rBound in result+1 jumps
		int result=1, lBound=1, rBound=A[0];
		while( rBound+1<n )
		{
			++ result;

			int newRBound = 0;
			for( int i=lBound; i<=rBound; ++i )
				newRBound = max( newRBound, i + A[i] );

			lBound = rBound+1;
			rBound = newRBound;
		}
		return result;
	}
};
