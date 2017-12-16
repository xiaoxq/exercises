/*
 * Problem: http://leetcode.com/onlinejudge#question_121
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		const int size = prices.size();
		if( size < 2 )
			return 0;

		// prices i stores the delta price
		for( int i=size-1; i>0; --i )
			prices[i] -= prices[i-1];
		prices[0] = 0;

		// add up the continuous deltas
		int result = 0;
		int sum = 0;
		for( int i=0; i<size; ++i )
		{
			sum += prices[i];
			if( sum < 0 )
				sum = 0;
			else
				result = max( result, sum );
		}
		return result;
	}
};
