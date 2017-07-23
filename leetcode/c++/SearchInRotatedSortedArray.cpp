/*
 * Problem: http://leetcode.com/onlinejudge#question_33
 */

class Solution
{
public:
	int search(int A[], int n, int target)
	{
		int left=0, right=n;
		while( left+1<right )
		{
			const int middle = (left+right)/2;
			if( A[left]<A[middle] )
			{
				(target>=A[left] && target<A[middle]) ? right=middle : left=middle;
			}
			else
			{
				(target >= A[middle] && target<=A[right-1]) ? left=middle : right=middle;
			}
		}
		// found or not
		return ( A[left]==target ) ? left : -1;
	}
};
