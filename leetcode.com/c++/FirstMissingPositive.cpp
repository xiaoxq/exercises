/*
 * Problem: http://leetcode.com/onlinejudge#question_41
 */

class Solution
{
public:
	int firstMissingPositive(int A[], int n)
	{
		for( int i=0; i<n; ++i)
		{
			if( A[i]!=i+1 && A[i]>0 && A[i]<n )
			{
				const int targetIndex = A[i]-1;
				if( A[i]==A[targetIndex] )
					continue;

				// swap
				int temp = A[targetIndex];
				A[targetIndex] = A[i];
				A[i] = temp;
				// swapped with someone behind me, deal with it
				if( i<targetIndex )
					--i;
			}
		}
		for( int i=0; i<n; ++i )
		{
			if( A[i]!=i+1 )
				return i+1;
		}
		return n+1;
	}
};
