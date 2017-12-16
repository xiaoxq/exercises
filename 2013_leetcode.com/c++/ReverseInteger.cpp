/*
 * Problem: http://leetcode.com/onlinejudge#question_7
 */

class Solution
{
public:
	int reverse(int x)
	{
		bool neg = (x<0);
		if( neg )
		{
			x=-x;
		}

		int result = 0;
		while( x>0 )
		{
			result *= 10;
			result += x % 10;
			x /= 10;
		}
		return (neg) ? -result : result;
	}
};
