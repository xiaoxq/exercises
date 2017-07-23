/*
 * Problem: http://leetcode.com/onlinejudge#question_57
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

class Solution
{
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		if( intervals.empty() )
		{
			intervals.push_back( newInterval );
			return intervals;
		}

		// find insert point in [left,right], using binary search
		int left=0, right=intervals.size();
		while( left+1 < right )
		{
			const int middle = (left+right) / 2;
			( newInterval.start >= intervals[middle].start ) ? left = middle : right = middle;
		}
		if( newInterval.start > intervals[left].start
			|| (newInterval.start==intervals[left].start && newInterval.end > intervals[left].end) )
			++left;

		// insert at left
		if( left==0 || newInterval.start > intervals[left-1].end )
			intervals.insert( intervals.begin() + left, newInterval );
		else
		{
			--left;
			intervals[left].end = max( intervals[left].end, newInterval.end );
		}

		// start merge at intervals[left]
		int mergeEnd = left+1;
		for( ; mergeEnd<intervals.size(); ++mergeEnd  )
		{
			if( intervals[left].end < intervals[mergeEnd].start )
				break;
		}
		intervals[left].end = max( intervals[left].end, intervals[mergeEnd-1].end);
		intervals.erase( intervals.begin()+left+1, intervals.begin()+mergeEnd );

		return intervals;
	}
};
