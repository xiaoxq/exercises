/*
 * Problem: http://leetcode.com/onlinejudge#question_32
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		const int len = s.length();
		int nMax=0;
		vector<int> pos;
		for( int i=0; i<len; ++i )
		{
			if( s[i] == '(')
				pos.push_back(i);
			else
			{
				if( !pos.empty() && s[ pos.back() ]=='(' )
				{
					pos.pop_back();
					if( pos.empty() )
						nMax = max( nMax, i+1 );
					else
						nMax = max( nMax, i-pos.back() );
				}
				else
				{
					pos.clear();
					pos.push_back( i );
				}
			}
		}
		return nMax;
	}  
};