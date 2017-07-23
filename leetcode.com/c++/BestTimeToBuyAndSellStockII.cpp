/*
 * Problem: http://leetcode.com/onlinejudge#question_122
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		const int size = prices.size();
		if( size < 2 )
			return 0;

		int result = 0;
		// prices i stores the delta price
		for( int i=size-1; i>0; --i )
		{
			int delta = prices[i] - prices[i-1];
			if( delta > 0 )
				result += delta;
		}

		return result;
	}
};
