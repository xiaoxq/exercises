/*
 * Problem: http://leetcode.com/onlinejudge#question_56
 */

#include <vector>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmpIntervalByStart( const Interval& l, const Interval& r )
{
	return l.start < r.start;
}

class Solution
{
public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		vector<Interval> result;
		if( intervals.empty() )
			return result;

		sort( intervals.begin(), intervals.end(), cmpIntervalByStart );

		Interval cur = intervals[0];
		const int size = intervals.size();
		for( int i=1; i<size; ++i )
		{
			if( intervals[i].start > cur.end )
			{
				result.push_back( cur );
				cur = intervals[i];
			}
			else if( intervals[i].end > cur.end )
				cur.end = intervals[i].end;
		}
		result.push_back( cur );
		return result;
	}
};
