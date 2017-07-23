/*
 * Problem: http://leetcode.com/onlinejudge#question_4
 */

#include <algorithm>
using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		const int median = (m+n)/2;
		double result = findKthInRange(A,m,B,n,median+1);
		if( (m+n) % 2 == 0 )
		{
			result += findKthInRange(A,m,B,n,median);
			result /= 2;
		}
		return result;
	}
private:
	int findKthInRange( int A[], int m, int B[], int n, int k )
	{
		int leftA = 0, rightA = m;
		int leftB = 0, rightB = n;

		while( leftA<rightA && leftB<rightB && k>1 )
		{
			const int middleA = (leftA+rightA)/2;
			const int middleB = (leftB+rightB)/2;

			// section 1: A[leftA,middleA] // section 2: A(middleA, rightA)
			// section 3: B[leftB,middleB) // section 4: B[middleB, rightB)
			if( A[middleA] <= B[middleB] )
			{
				// throw section 4
				if( middleA-leftA+1 + middleB-leftB >= k )
				{
					rightB = middleB;
				}
				// throw section 1
				else
				{
					k -= middleA-leftA+1;
					leftA = middleA+1;
				}
			}
			// section 1: A[leftA,middleA) // section 2: A[middleA, rightA)
			// section 3: B[leftB,middleB] // section 4: B(middleB, rightB)
			else
			{
				// throw section 2
				if( middleA-leftA+1 + middleB-leftB >= k )
				{
					rightA = middleA;
				}
				// throw section 3
				else
				{
					k -= middleB-leftB+1;
					leftB = middleB+1;
				}
			}
		}

		// when reach here, leftA==rightA || leftB==rightB || k==1
		int result = 0;
		if(leftA==rightA)
		{
			result = B[leftB+k-1];
		}
		else if(leftB==rightB)
		{
			result = A[leftA+k-1];
		}
		else if( k==1 )
		{
			result = min(A[leftA],B[leftB]);
		}

		return result;
	}
};
