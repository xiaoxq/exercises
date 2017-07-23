/*
 * Problem: http://leetcode.com/onlinejudge#question_15
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
		vector<vector<int> > result;
		if( num.empty() )
			return result;

		sort( num.begin(), num.end() );
		for( int i=0; i<num.size(); ++i )
		{
			// no duplicate
			if( i>0 && num[i]==num[i-1] )
				continue;
			twoSum( num, i, result);
		}
		return result;
	}

private:
	void twoSum(const vector<int>& num, int minNumIndex, vector<vector<int> >& result)
	{
		int left=minNumIndex+1, right=num.size()-1, sum=-num[minNumIndex];
		while( left<right )
		{
			// no duplicate
			if( left>minNumIndex+1 && num[left]==num[left-1] )
			{
				++ left;
				continue;
			}

			const int cur_sum = num[left] + num[right];
			if( cur_sum == sum )
			{
				vector<int> solution(3);
				solution[0] = num[minNumIndex];
				solution[1] = num[left];
				solution[2] = num[right];
				result.push_back( solution );
				++ left;
				-- right;
			}
			else
			{
				( cur_sum>sum ) ? --right : ++left;
			}
		}
	}
};
