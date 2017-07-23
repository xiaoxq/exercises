/*
 * Problem: http://leetcode.com/onlinejudge#question_9
 */

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if(x<0)
		{
			return false;
		}

		// find the largest 10's factor
		int tens_l = 1;
		while(x/tens_l >= 10)
		{
			tens_l *= 10;
		}

		int tens_r = 1;
		while( tens_l>tens_r )
		{
			if( (x/tens_l % 10) != (x/tens_r % 10) )
			{
				return false;
			}
			tens_l /= 10;
			tens_r *= 10;
		}
		return true;
	}
};
