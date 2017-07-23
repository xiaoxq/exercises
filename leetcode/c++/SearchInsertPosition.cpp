/*
 * Problem: http://leetcode.com/onlinejudge#question_35
 */

class Solution
{
public:
	int searchInsert(int A[], int n, int target)
	{
		// target is in [left,right)
		int left=0, right=n;
		while( left+1<right )
		{
			const int middle = (left+right) / 2;
			( A[middle]>target ) ? right = middle : left = middle;
		}
		return (A[left]<target) ? left+1 : left;
	}
};
