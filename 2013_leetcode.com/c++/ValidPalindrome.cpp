/*
 * Problem: http://leetcode.com/onlinejudge#question_125
 */

#include <string>
using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		int left=0, right=s.length()-1;
		while( left<right )
		{
			// move left to the next char
			const char cLeft = valid(s[left]);
			if( cLeft=='\0' )
			{
				++left;
				continue;
			}
			// move right to the next char
			const char cRight = valid(s[right]);
			if( cRight=='\0' )
			{
				--right;
				continue;
			}
			if( cLeft!=cRight )
				return false;

			++left;
			--right;
		}
		return true;
	}
private:
	inline char valid( const char c )
	{
		if( c>='0' && c<='9' )
			return c;
		if( c>='a' && c<='z' )
			return c;
		if( c>='A' && c<='Z' )
			return c-'A'+'a';
		return '\0';
	}
};
