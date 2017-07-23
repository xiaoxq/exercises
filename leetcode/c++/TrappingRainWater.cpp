/*
 * Problem: http://leetcode.com/onlinejudge#question_42
 */

class Solution
{
public:
	int trap(int A[], int n)
	{
		int result=0;
		int left=0, right=n-1;

		// left, right are current max height
		while( left<right )
		{
			// move left forward
			if( A[left]<A[right] )
			{
				int i=left+1;
				for( ; i<right && A[i]<=A[left]; ++i )
					result += A[left]-A[i];
				left = i;
			}
			// move right forward
			else
			{
				int i=right-1;
				for( ; i>left && A[i]<=A[right]; --i )
					result += A[right]-A[i];
				right = i;
			}
		}
		return result;
	}
};
