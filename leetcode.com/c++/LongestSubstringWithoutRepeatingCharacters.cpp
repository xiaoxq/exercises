/*
 * Problem: http://leetcode.com/onlinejudge#question_3
 */

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int maxLen = 0;
		const int len = s.length();
		vector<bool> showup('z'-'a'+1, false);

   		int left=0, right=0;
		while( left+maxLen < len && right < len )
		{
			if( !showup[ s[right]-'a' ] )
			{
				// mark
				showup[ s[right]-'a' ] = true;
				++right;
			}
			else
			{
				// revert
				showup[ s[left]-'a' ] = false;
				maxLen = max( maxLen, right-left );
				++left;
			}
		}
		maxLen = max( maxLen, right-left );
		return maxLen;
	}
};
