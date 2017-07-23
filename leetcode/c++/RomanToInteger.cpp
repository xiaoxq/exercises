/*
 * Problem: http://leetcode.com/onlinejudge#question_13
 */

#include <map>
#include <string>
using namespace std;

string digits1[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
string digits10[] = { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
string digits100[] = { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
string digits1000[] = { "M", "MM", "MMM" };

class Solution
{
public:
	Solution()
	{
		for( int i=0; i<9; ++i )
		{
			rtoi.insert( make_pair(digits1[i], (i+1)) );
			rtoi.insert( make_pair(digits10[i], (i+1)*10) );
			rtoi.insert( make_pair(digits100[i], (i+1)*100) );
			if( i<3 )
				rtoi.insert( make_pair(digits1000[i], (i+1)*1000) );
		}
	}

	int romanToInt(string s)
	{
		int ret=0, start=0;
		while( start<s.length() )
		{
			int end = start+1;
			for( ; end<=s.length(); ++end )
			{
				if( rtoi.find( s.substr(start,end-start) ) != rtoi.end() )
					continue;
				ret += rtoi[ s.substr(start,end-start-1) ];
				start = end-1;
				break;
			}
			if( end>s.length() )
			{
				ret += rtoi[ s.substr(start,end-start-1) ];
				break;
			}
		}
		return ret;
	}
private:
	map<string,int> rtoi;
};
