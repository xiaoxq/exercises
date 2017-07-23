/*
 * Problem: http://leetcode.com/onlinejudge#question_88
 */

class Solution
{
public:
	void merge(int A[], int m, int B[], int n)
	{
		int i=m-1, j=n-1;
		for( ; i>=0 && j>=0; )
		{
			if( A[i]>B[j] )
			{
				A[ i+j+1 ] = A[i];
				--i;
			}
			else
			{
				A[ i+j+1 ] = B[j];
				--j;
			}
		}
		while( j>=0 )
		{
			A[j] = B[j];
			--j;
		}
	}
};
