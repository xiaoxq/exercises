/*
 * Problem: http://leetcode.com/onlinejudge#question_27
 */

class Solution
{
public:
	int removeElement(int A[], int n, int elem)
	{
		int writePos=0;
		for( int i=0; i<n; ++i )
		{
			if( A[i]!=elem )
				A[writePos++] = A[i];
		}
		return writePos;
	}
};
