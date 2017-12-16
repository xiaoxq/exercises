/*
 * Problem: http://leetcode.com/onlinejudge#question_123
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

		vector<int> bestProfitFrom0Toi( size, 0 );
		vector<int> bestProfitFromiTon( size, 0 );
		int sum=0, bestProfit=0;
		for( int i=0; i<size; ++i )
		{
			sum += prices[i];
			if( sum<0 )
				sum = 0;
			else
				bestProfit = max( bestProfit, sum );
			bestProfitFrom0Toi[i] = bestProfit;
		}

		sum=0;
		bestProfit=0;
		for( int i=0; i<size; ++i )
		{
			sum += prices[size-1-i];
			if( sum<0 )
				sum = 0;
			else
				bestProfit = max( bestProfit, sum );
			bestProfitFromiTon[size-1-i] = bestProfit;
		}

		bestProfit=0;
		for( int i=0; i+1<size; ++i )
		{
			sum = bestProfitFrom0Toi[i] + bestProfitFromiTon[i+1];
			bestProfit = max( bestProfit, sum );
		}
		return bestProfit;
	}
};
