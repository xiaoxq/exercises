/*
 * Problem: http://leetcode.com/onlinejudge#question_59
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > generateMatrix(int n)
	{
		vector<vector<int> > result( n, vector<int>(n) );

		int leftBound = 0, upperBound = 0, rightBound = n-1, lowerBound = n-1;

		int num = 0;
		while( leftBound <= upperBound || upperBound <= lowerBound )
		{
			for( int i=leftBound; i<=rightBound; ++i )
				result[upperBound][i] = ++num;
			if( ++upperBound > lowerBound )
				break;

			for( int i=upperBound; i<=lowerBound; ++i )
				result[i][rightBound] = ++num;
			if( --rightBound < leftBound )
				break;

			for( int i=rightBound; i>=leftBound; --i )
				result[lowerBound][i] = ++num;
			if( --lowerBound < upperBound )
				break;

			for( int i=lowerBound; i>=upperBound; --i )
				result[i][leftBound] = ++num;
			if( ++leftBound > rightBound )
				break;
		}
		return result;
	}
};
