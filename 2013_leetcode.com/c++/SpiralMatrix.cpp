/*
 * Problem: http://leetcode.com/onlinejudge#question_54
 */

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		if( matrix.empty() )
			return result;

		int leftBound = 0, upperBound = 0;
		int rightBound = matrix[0].size() - 1;
		int lowerBound = matrix.size() - 1;

		while( leftBound <= upperBound || upperBound <= lowerBound )
		{
			for( int i=leftBound; i<=rightBound; ++i )
				result.push_back( matrix[upperBound][i] );
			if( ++upperBound > lowerBound )
				break;

			for( int i=upperBound; i<=lowerBound; ++i )
				result.push_back( matrix[i][rightBound] );
			if( --rightBound < leftBound )
				break;

			for( int i=rightBound; i>=leftBound; --i )
				result.push_back( matrix[lowerBound][i] );
			if( --lowerBound < upperBound )
				break;

			for( int i=lowerBound; i>=upperBound; --i )
				result.push_back( matrix[i][leftBound] );
			if( ++leftBound > rightBound )
				break;
		}
		return result;
	}
};
