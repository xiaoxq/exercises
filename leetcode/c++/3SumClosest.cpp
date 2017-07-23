/*
 * Problem: http://leetcode.com/onlinejudge#question_16
 */

#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &num, int target)
	{
		int minDiff = INT_MAX;
		bool neg = false;
		sort( num.begin(), num.end() );

		const int len = num.size();
		for( int i=0; i<len; ++i )
		{
			int left=i+1, right=len-1, targetSum=target-num[i];
			int curDiff = INT_MAX;
			bool curNeg = false;

			while( left<right )
			{
				const int curSum = num[left] + num[right];
				if( curSum < targetSum )
				{
					curDiff = targetSum - curSum;
					curNeg = true;
					++ left;
				}
				else if( curSum > targetSum )
				{
					curDiff = curSum - targetSum;
					curNeg = false;
					-- right;
				}
				// the diff is 0
				else
				{
					return target;
				}

				if( curDiff < minDiff )
				{
					minDiff = curDiff;
					neg = curNeg;
				}
			}
		}
		return (neg) ? target - minDiff : target + minDiff;
	}
};
