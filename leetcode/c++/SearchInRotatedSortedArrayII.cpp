/*
 * Problem: http://leetcode.com/onlinejudge#question_81
 */

class Solution
{
public:
	bool search(int A[], int n, int target)
	{
		return binarySearchInRotatedArray( A, 0, n, target );
	}
private:
	bool binarySearchInRotatedArray( int A[], int left, int right, int target )
	{
		while( left+1<right )
		{
			const int middle = (left+right) / 2;
			// find the unrotated half
			int i=middle-1;
			for( ; i>=left; --i )
			{
				if( A[i]!=A[middle] )
					break;
			}
			if( i<left )
			{
				left = middle;
				continue;
			}

			if( A[left]<=A[i] )
				(target>=A[left] && target<=A[i]) ? right=i+1 : left=middle;
			else
				(target>=A[middle] && target<=A[right-1]) ? left=middle : right=i+1;
		}
		// found or not
		return A[left]==target;
	}
};
