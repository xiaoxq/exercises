/*
 * Problem: http://leetcode.com/onlinejudge#question_38
 */

#include <string>
#include <stdio.h>
using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		string result("1");
		while( --n > 0 )
			result = nextCountAndSay(result);
		return result;
	}
private:
	string nextCountAndSay( const string& num )
	{
		// in the worst case, new string is double size of n
		char* buf = new char[ num.length() * 2 + 1 ];
		int writePos = 0;
		for( int rangeStart=0; rangeStart<num.length(); )
		{
			int rangeEnd = rangeStart+1;
			for( ; rangeEnd<num.length(); ++rangeEnd )
			{
				if( num[rangeEnd] != num[rangeStart] )
					break;
			}
			int count = rangeEnd-rangeStart;
			sprintf( buf+writePos, "%d%c", count, num[rangeStart] );
			while( buf[writePos]!=0 )
				++writePos;
			rangeStart = rangeEnd;
		}
		string result(buf);
		delete[] buf;
		return result;
	}
};
