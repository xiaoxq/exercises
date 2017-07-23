/*
 * Problem: http://leetcode.com/onlinejudge#question_69
 */

class Solution
{
public:
	int sqrt(int x)
	{
		if(x<=0)
			return 0;

		int numOfBits = 1;
		while( x >> numOfBits )
			++numOfBits;

		int result = 0;
		for( int bitPos = (numOfBits - 1) / 2; bitPos>=0; --bitPos )
		{
			int withTheBit = result | ( 1<<bitPos );
			if( x / withTheBit >= withTheBit )
				result = withTheBit;
		}
		return result;
	}
};
