/*
 * Problem: http://leetcode.com/onlinejudge#question_53
 */

#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxSubArray(int A[], int n)
	{
		// A[0]+..+A[i] stores in sum[i]
		int* sum = new int[n];
		sum[0] = A[0];
		for( int i=1; i<n; ++i )
			sum[i] = sum[i-1] + A[i];

		// divide and conquer
		return maxSubArray( A, sum, 0, n, n );
	}
private:
	// return max sum in [start,end)
	int maxSubArray(int* A, int* sum, int start, int end, int n)
	{
		// solve directly
		switch( end-start )
		{
		case 1: return A[start];
		case 2: return max( max( A[start], A[start+1] ), A[start] + A[start+1] );
		}

		const int middle = (start + end) / 2;
		const int childResult = max( maxSubArray( A, sum, start, middle, n ),
				maxSubArray( A, sum, middle+1, end, n ));

		// find max in sum after middle
		const int maxSum = max_element( sum+middle, sum+n );
		// find min in sum before middle
		const int minSum = min_element( sum, sum+middle );
		return max( childResult, maxSum - minSum );
	}
};
