/*
 * Problem: http://leetcode.com/onlinejudge#question_132
 */

#include <vector>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution
{
public:
	int minCut(string s)
	{
		const int len = s.length();

		vector<vector<bool> > palindromes( len, vector<bool>(len, false) );
		for( int i=0; i<len; ++i )
		{
			for( int left=0, right=left+i; right<len; ++left, ++right )
			{
				if( i==0 )
					palindromes[left][right] = true;
				else if( i==1 )
					palindromes[left][right] = (s[left]==s[right]);
				else
					palindromes[left][right] = (s[left]==s[right] && palindromes[left+1][right-1]);
			}
		}

		// minCutsFromiton[i] records the min cut of [i,len)
		vector<int> minCutsFromiton( len, INT_MAX );
		for( int i=len-1; i>=0; --i )
		{
			if( palindromes[i][len-1] )
			{
				minCutsFromiton[i] = 0;
			}
			else
			{
				for( int j=len-2; j>=i; --j )
				{
					if( palindromes[i][j] )
						minCutsFromiton[i] = min( minCutsFromiton[i], minCutsFromiton[j+1] + 1 );
				}
			}
		}
		return minCutsFromiton[0];
	}
};
