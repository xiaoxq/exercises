/*
 * Problem: http://leetcode.com/onlinejudge#question_26
 */

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if( n<=0 )
			return 0;

		int lastWritePos=0, readPos=1;
		while( readPos<n )
		{
			if( A[lastWritePos]!=A[readPos] )
			{
				A[++lastWritePos] = A[readPos];
			}
			++readPos;
		}
		return lastWritePos+1;
	}
};
