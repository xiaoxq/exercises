/*
 * Problem: http://leetcode.com/onlinejudge#question_77
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combine(int n, int k)
	{
		vector<vector<int> > result;
		vector<int> prefix;
		fillRemain( 1, n, k, result, prefix);
		return result;
	}
private:
	void fillRemain( int start, int end, int k, vector<vector<int> >& result, vector<int>& prefix )
	{
		if( k==0 )
		{
			if( !prefix.empty() )
				result.push_back( prefix );
			return;
		}

		for( int i=start; i+k-1<=end; ++i )
		{
			prefix.push_back( i );
			fillRemain( i+1, end, k-1, result, prefix );
			prefix.pop_back();
		}
	}
};
