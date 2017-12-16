/*
 * Problem: http://leetcode.com/onlinejudge#question_96
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		vector<int> treeNum( n, 0 );
		treeNum[0] = 1;
		for( int i=1; i<n; ++i )
		{
			treeNum[i] = treeNum[i-1] * 2;
			for( int j=1; j<i; ++j )
				treeNum[i] += treeNum[j-1] * treeNum[i-1-j];
		}
		return treeNum[n-1];
	}
};
