/*
 * Problem: http://leetcode.com/onlinejudge#question_78
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > subsets(vector<int> &S)
	{
		vector<vector<int> > result;
		sort( S.begin(), S.end() );
		getSubsets( S, S.begin(), result );
		return result;
	}
private:
	void getSubsets( const vector<int> &S, vector<int>::const_iterator cur,
			vector<vector<int> >& result )
	{
		// return an empty subset
		if( cur == S.end() )
		{
			result.push_back( vector<int>() );
			return;
		}

		getSubsets( S, cur+1, result );
		int count = result.size();
		vector<int> withMe( 1, *cur );
		for( int i=0; i<count; ++i )
		{
			withMe.insert( withMe.end(), result[i].begin(), result[i].end() );
			result.push_back( withMe );
			withMe.resize(1);
		}
	}
};
