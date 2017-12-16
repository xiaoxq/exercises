/*
 * Problem: http://leetcode.com/onlinejudge#question_73
 */

#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if( matrix.empty() || matrix[0].empty() )
			return;

		const int m = matrix.size();
		const int n = matrix[0].size();

		// use row0, col0 to record mark
		// and use setRow0, setCol0 to record itself
		bool setRow0 = false, setCol0 = false;
		for( int i=0; i<m; ++i )
		{
			if( matrix[i][0]==0 )
			{
				setCol0 = true;
				break;
			}
		}
		for( int j=0; j<n; ++j )
		{
			if( matrix[0][j]==0 )
			{
				setRow0 = true;
				break;
			}
		}

		for( int i=0; i<m; ++i )
		{
			for( int j=0; j<n; ++j )
				if( matrix[i][j]==0 )
					matrix[i][0] = matrix[0][j] = 0;
		}
		for( int i=1; i<m; ++i )
		{
			if( matrix[i][0]==0 )
			{
				for( int j=1; j<n; ++j )
					matrix[i][j] = 0;
			}
		}
		for( int j=1; j<n; ++j )
		{
			if( matrix[0][j]==0 )
			{
				for( int i=1; i<m; ++i )
					matrix[i][j] = 0;
			}
		}
		if( setCol0 )
		{
			for( int i=0; i<m; ++i )
				matrix[i][0] = 0;
		}
		if( setRow0 )
		{
			for( int j=0; j<n; ++j )
				matrix[0][j] = 0;
		}
	}
};
