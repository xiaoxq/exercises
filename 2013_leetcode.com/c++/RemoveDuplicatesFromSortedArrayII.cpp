/*
 * Problem: http://leetcode.com/onlinejudge#question_80
 */

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		const int AllowedDuplicates = 2;
		if( n <= AllowedDuplicates )
			return n;

		int writePos=1, curDuplicates=1;
		for( int readPos=1; readPos<n; ++readPos )
		{
			// another duplicate
			if( A[readPos]==A[writePos-1] )
			{
				++curDuplicates;
				if( curDuplicates <= AllowedDuplicates )
					A[writePos++] = A[readPos];
			}
			else
			{
				A[writePos++] = A[readPos];
				curDuplicates = 1;
			}
		}
		return writePos;
	}
};
