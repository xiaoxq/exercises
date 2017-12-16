/*
 * Problem: http://leetcode.com/onlinejudge#question_72
 */

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		const int len1 = word1.length();
		const int len2 = word2.length();
		if( len1==0 )
			return len2;
		if( len2==0 )
			return len1;

		vector< vector<int> > editDist( len1, vector<int>( len2, -1 ) );
		return getEditDistance( editDist, word1, 0, word2, 0 );
	}
private:
	int getEditDistance( vector< vector<int> >& editDist,
			const string& word1, const int index1,
			const string& word2, const int index2 )
	{
		const int len1 = word1.length();
		const int len2 = word2.length();
		if( index1==len1 )
			return len2-index2;
		if( index2==len2 )
			return len1-index1;

		if( editDist[index1][index2]>=0 )
			return editDist[index1][index2];

		if( word1[index1]==word2[index2] )
			editDist[index1][index2] = getEditDistance( editDist, word1, index1+1, word2, index2+1 );
		else
		{
			// insert one
			int dist = min ( getEditDistance( editDist, word1, index1+1, word2, index2 ),
					getEditDistance( editDist, word1, index1, word2, index2+1 ) );
			// replace one
			dist = min( dist, getEditDistance( editDist, word1, index1+1, word2, index2+1 ) );
			editDist[index1][index2] = 1 + dist;
		}
		return editDist[index1][index2];
	}
};

