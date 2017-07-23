/*
 * Problem: http://leetcode.com/onlinejudge#question_5
 */

#include <string>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		const int len = s.length();
		int longestLen = 0, startPos = 0;
		for( int centerPos=0; centerPos < len; ++centerPos )
		{
			int best = max(
				// aba, centerPos point at b
				getPalindromeLen(s,centerPos-1,centerPos+1),
				// abba, centerPos point at 2nd b
				getPalindromeLen(s,centerPos-1,centerPos) );
			if( best > longestLen )
			{
				longestLen = best;
				startPos = centerPos - best / 2;
			}
		}
		return s.substr( startPos, longestLen );
	}
private:
	int getPalindromeLen(const string& s, int left, int right)
	{
		const int len = s.length();
		while( left>=0 && right<len && s[left]==s[right] )
		{
			--left;
			++right;
		}
		return right-left-1;
	}
};
