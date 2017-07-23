/*
 * Problem: http://leetcode.com/onlinejudge#question_84
 */

#include <vector>
using namespace std;

struct ContinuousHeightCount
{
	int height;
	int count;
	ContinuousHeightCount( int h, int c )
	{
		height = h;
		count = c;
	}
};

class Solution
{
public:
	int largestRectangleArea(vector<int> &height)
	{
		vector<ContinuousHeightCount> continuousHeightCount;
		int result = 0;

		for( vector<int>::const_iterator it=height.begin(); it!=height.end(); ++it )
		{
			// settle those higher than current height
			int addupCount = 0;
			while( !continuousHeightCount.empty() )
			{
				ContinuousHeightCount& hc = continuousHeightCount.back();
				if( hc.height <= *it )
					break;
				addupCount += hc.count;
				result = max( result, addupCount * hc.height );
				continuousHeightCount.pop_back();
			}
			// insert new entry if needed
			if( continuousHeightCount.empty() || continuousHeightCount.back().height != *it )
				continuousHeightCount.push_back( ContinuousHeightCount(*it, addupCount+1) );
			else
				continuousHeightCount.back().count += addupCount+1;
		}

		// settle all
		int addupCount = 0;
		for( vector<ContinuousHeightCount>::const_reverse_iterator it=continuousHeightCount.rbegin();
				it!=continuousHeightCount.rend(); ++it )
		{
			addupCount += it->count;
			result = max( result, addupCount * it->height );
		}
		return result;
	}
};
