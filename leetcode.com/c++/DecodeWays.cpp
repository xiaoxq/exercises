/*
 * Problem: http://leetcode.com/onlinejudge#question_91
 */

#include <string>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		if( s.empty() )
			return 0;

		const int len = s.length();
		vector<int> num( len+1, 0 );

		// init
		num[ len ] = 1;
		for( int i=len-1; i>=0; --i )
		{
			if( s[i]!='0' )
			{
				// decode by 1 char
				num[i] = num[i+1];

				// try decoding by 2 chars
				if( i+1<len && ( s[i]=='1' || ( s[i]=='2' && s[i+1]<='6' ) ) )
					num[i] += num[i+2];
			}
		}
		return num[0];
	}
};
