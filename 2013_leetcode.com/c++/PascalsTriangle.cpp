/*
 * Problem: http://leetcode.com/onlinejudge#question_118
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > generate(int numRows)
	{
		vector<vector<int> > result;
		if( numRows==0 )
			return result;

		// row 1
		result.push_back( vector<int>(1,1) );

		vector<int> curRow( 1, 1 );
		for( int row=2; row<=numRows; ++row )
		{
			const vector<int>& lastRow = result[row-2];

			for( int col=1; col <= row-2; ++col )
				curRow.push_back( lastRow[col-1]+lastRow[col] );

			curRow.push_back( 1 );
			result.push_back( curRow );
			curRow.resize( 1 );
		}

		return result;
	}
};
