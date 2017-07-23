/*
 * Problem: http://leetcode.com/onlinejudge#question_8
 */

#include <stdio.h>
#include <limits.h>
#include <cctype>

class Solution
{
public:
	int atoi(const char *str)
	{
		int index = 0;
		// get to the first non-whitespace char
		while( isspace( str[index] ) )
		{
			++ index;
		}

		// with signed or not
		bool isNeg = (str[index] == '-');
		if( str[index] == '-' || str[index] == '+' )
		{
			++ index;
		}

		int result = 0, lastresult = 0;
		for( ; str[index]>='0' && str[index]<='9'; ++index )
		{
			result = 10 * lastresult + str[index] - '0';
			// overflow
			if( result/10 != lastresult )
			{
				return (isNeg) ? INT_MIN : INT_MAX;
			}
			lastresult = result;
		}
		return (isNeg) ? -result : result;
	}
};
