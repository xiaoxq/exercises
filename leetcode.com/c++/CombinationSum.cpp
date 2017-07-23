/*
 * Problem: http://leetcode.com/onlinejudge#question_39
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int> > result;
		vector<int> prefix;

		sort(candidates.begin(), candidates.end());
		findCombinations( result, candidates, 0, prefix, target );
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
		findCombinations( result, candidates, index, prefix, target-candidates[index] );
		prefix.pop_back();

		// no use candidates[index]
		findCombinations( result, candidates, index+1, prefix, target );
	}
};
