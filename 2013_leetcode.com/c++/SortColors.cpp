/*
 * Problem: http://leetcode.com/onlinejudge#question_75
 */

enum Color
{
	RED = 0,
	WHITE = 1,
	BLUE = 2
};

class Solution
{
public:
	void sortColors(int A[], int n)
	{
		int writeRed=0, writeBlue=n-1, read=0;
		while( read<=writeBlue )
		{
			switch(A[read])
			{
			case RED: swap( A[writeRed++], A[read++] ); break;
			case WHITE: ++read; break;
			case BLUE: swap( A[writeBlue--], A[read] ); break;
			}
		}
	}
private:
	inline void swap( int& a, int& b )
	{
		if( a!=b )
		{
			int temp = a;
			a = b;
			b = temp;
		}
	}
};
