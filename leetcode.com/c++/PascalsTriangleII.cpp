/*
 * Problem: http://leetcode.com/onlinejudge#question_119
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result( rowIndex+1, 1 );
		for( int definePos=rowIndex-1; definePos>=(rowIndex+1)/2; --definePos )
		{
			for( int i=1; i<=definePos; ++i )
				result[i] += result[i-1];
		}
		// mirror
		for( int i=1, j=rowIndex-1; i<j; ++i, --j )
			result[i] = result[j];
		return result;
	}
};
