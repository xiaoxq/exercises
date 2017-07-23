/*
 * Problem: http://leetcode.com/onlinejudge#question_14
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		const int size = strs.size();
		if( size==0 )
		{
			return "";
		}

		for( int prefixLen=0; prefixLen<strs[0].length(); ++prefixLen )
		{
			for( int i=1; i<size; ++i )
			{
				if( strs[i][prefixLen]!=strs[0][prefixLen] )
					return prefixLen>0 ? strs[0].substr(0,prefixLen) : "";
			}
		}
		return strs[0];
	}
};
