/*
 * Problem: http://leetcode.com/onlinejudge#question_34
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(int A[], int n, int target)
	{
		vector<int> result(2, -1);

		// leftbound is in (left,right]
		int left=-1, right=n-1;
		while( left+1<right )
		{
			const int middle = (left+right)/2;
			( A[middle]<target ) ? left = middle : right = middle;
		}

		if( A[right]==target )
		{
			result[0] = right;

			// rightbound is in [left,right)
			left=0, right=n;
			while( left+1<right )
			{
				const int middle = (left+right)/2;
				( A[middle]>target ) ? right = middle : left = middle;
			}
			result[1] = left;
		}

		return result;
	}
};
