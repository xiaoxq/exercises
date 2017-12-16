/*
 * Problem: http://leetcode.com/onlinejudge#question_40
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target)
	{
		vector<vector<int> > result;
		vector<int> prefix;

		sort(num.begin(), num.end());
		findCombinations( result, num, 0, prefix, target );
		return result;
	}
private:
	void findCombinations( vector<vector<int> >& result,
			const vector<int>& candidates, int index,
			vector<int>& prefix, int target )
	{
		// exact
		if( target==0 )
		{
			result.push_back( prefix );
			return;
		}
		// out of index or exceed
		if( index==candidates.size() || candidates[index]>target )
			return;

		// use candidates[index] once
		prefix.push_back( candidates[index] );
		findCombinations( result, candidates, index+1, prefix, target-candidates[index] );
		prefix.pop_back();

		// no use candidates[index], and all its brothers
		while( index+1<candidates.size() && candidates[index+1]==candidates[index] )
			++index;
		findCombinations( result, candidates, index+1, prefix, target );
	}
};
