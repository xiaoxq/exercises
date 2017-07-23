/*
 * Problem: http://leetcode.com/onlinejudge#question_55
 */

#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n)
	{
		if( n==1 )
			return true;

		// reach [lBound,rBound) in the same steps
		int lBound=1, rBound=A[0]+1;
		while( rBound<n && lBound<rBound )
		{
			int newRBound = 0;
			for( int i=lBound; i<rBound; ++i )
				newRBound = max( newRBound, i + A[i] );
			lBound = rBound;
			rBound = newRBound + 1;
		}
		return (rBound>=n);
	}
};
