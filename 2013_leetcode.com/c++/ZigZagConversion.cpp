/*
 * Problem: http://leetcode.com/onlinejudge#question_6
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string convert(string s, int nRows)
	{
		vector<string> row( nRows );
		const int len = s.length();

		int pos = 0;
		for( int col=0; ; ++col )
		{
			if( col%2==0 )
			{
				for( int i=0; i<nRows && pos<len; ++i )
					row[i].append( 1, s[pos++] );
			}
			else
			{
				for( int i=nRows-2; i>=1 && pos<len; --i )
					row[i].append( 1, s[pos++] );
			}
			if(pos==len)
				break;
		}
		string result;
		for( int i=0; i<nRows; ++i )
		{
			result.append( row[i] );
		}
		return result;
	}
};
