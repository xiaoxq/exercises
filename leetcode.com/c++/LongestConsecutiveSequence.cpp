/*
 * Problem: http://leetcode.com/onlinejudge#question_128
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &num)
	{
		// use hash-based set, not tree-based set
		unordered_set<int> showup;

		for( vector<int>::const_iterator it=num.begin(); it!=num.end(); ++it )
			showup.insert( *it );

		int maxLen = 1, curLen;
		for( vector<int>::const_iterator it=num.begin(); it!=num.end(); ++it )
		{
			if( showup.find( *it )==showup.end() )
				continue;

			curLen = 1;
			for( int i=*it-1; showup.find( i )!=showup.end(); --i )
			{
				++curLen;
				showup.erase( i );
			}
			for( int i=*it+1; showup.find( i )!=showup.end(); ++i )
			{
				++curLen;
				showup.erase( i );
			}
			maxLen = max(maxLen, curLen);
		}
		return maxLen;
	}
};
