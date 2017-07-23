/*
 * Problem: http://leetcode.com/onlinejudge#question_11
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
		int maxArea = 0;
		int x1 = 0, x2 = height.size() - 1;
		while( x1<x2 )
		{
			const int area = (x2-x1) * min( height[x1], height[x2] );
			maxArea = max( maxArea, area );
			( height[x1] < height[x2] ) ? ++x1 : --x2;
		}
		return maxArea;
	}
};
