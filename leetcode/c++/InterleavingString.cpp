/*
 * Problem: http://leetcode.com/onlinejudge#question_97
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		const int len1 = s1.length();
		const int len2 = s2.length();

		if( len1 + len2 != s3.length() )
			return false;

		vector< vector<bool> > cache( len1+1, vector<bool>( len2+1, false ) );

		// cache[i][j] means using i from s1, and j from s2
		cache[0][0] = true;
		for( int i=1; i<=len1 && s1[i-1]==s3[i-1]; ++i )
			cache[i][0] = true;
		for( int j=1; j<=len2 && s2[j-1]==s3[j-1]; ++j )
			cache[0][j] = true;

		for( int i=1; i<=len1; ++i )
		{
			for( int j=1; j<=len2; ++j )
				cache[i][j] = (cache[i-1][j] && s1[i-1]==s3[i+j-1]) || (cache[i][j-1] && s2[j-1]==s3[i+j-1]);
		}
		return cache[len1][len2];
	}
};
