/*
 * Problem: http://leetcode.com/onlinejudge#question_115
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int numDistinct(string S, string T)
	{
		if( S.empty() || T.empty() )
			return 0;

		vector< vector<int> > cache( S.length(), vector<int>( T.length(), -1 ) );
		return numDistinct( S,0,T,0,cache );
	}
private:
	int numDistinct(string& S, const int sIndex, string& T, const int tIndex,
			vector< vector<int> >& cache)
	{
		const int lenS = S.length();
		const int lenT = T.length();

		if( tIndex==lenT )
			return 1;
		if( sIndex==lenS )
			return 0;

		if( cache[sIndex][tIndex] >= 0 )
			return cache[sIndex][tIndex];

		cache[sIndex][tIndex] = 0;
		for( int i=sIndex; i+(lenT-tIndex) <= lenS; ++i )
		{
			if( S[i]==T[tIndex] )
				cache[sIndex][tIndex] += numDistinct( S, i+1, T, tIndex+1, cache );
		}
		return cache[sIndex][tIndex];
	}
};
