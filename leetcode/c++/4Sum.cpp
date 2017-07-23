/*
 * Problem: http://leetcode.com/onlinejudge#question_18
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > fourSum(vector<int> &num, int target)
	{
		vector<vector<int> > result;
		if( num.empty() )
			return result;

		sort( num.begin(), num.end() );
		for( int index0=0; index0<num.size(); ++index0 )
		{
			if( index0>0 && num[index0]==num[index0-1] )
				continue;
			threeSum( num, index0, target, result );
		}
		return result;
	}
private:
	void threeSum(const vector<int>& num, int index0, int target, vector<vector<int> >& result)
	{
		for( int index1=index0+1; index1<num.size(); ++index1 )
		{
			if( index1>index0+1 && num[index1]==num[index1-1] )
				continue;

			int index2=index1+1, index3=num.size()-1, local_target=target-num[index0]-num[index1];
			while( index2<index3 )
			{
				if( index2>index1+1 && num[index2] == num[index2-1] )
				{
					++ index2;
					continue;
				}

				int cur_sum = num[index2] + num[index3];
				if( cur_sum == local_target )
				{
					vector<int> solution(4);
					solution[0] = num[index0];
					solution[1] = num[index1];
					solution[2] = num[index2];
					solution[3] = num[index3];
					result.push_back( solution );
					++ index2;
					-- index3;
				}
				else
				{
					cur_sum > local_target ? --index3 : ++index2;
				}
			}
		}
	}
};
