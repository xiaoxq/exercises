/*
 * Problem: http://leetcode.com/onlinejudge#question_90
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S)
	{
		if( S.empty() )
			// an empty set
			return vector< vector<int> >( 1, vector<int>() );

		sort( S.begin(), S.end() );
		vector<vector<int> > resultWithMe, resultWithoutMe;
		getSubsets( S, S.begin(), resultWithMe, resultWithoutMe );
		resultWithMe.insert( resultWithMe.end(), resultWithoutMe.begin(), resultWithoutMe.end() );
		return resultWithMe;
	}
private:
	// return the head's value
	int getSubsets( const vector<int> &S, vector<int>::const_iterator cur,
			vector<vector<int> >& resultWithMe, vector<vector<int> >& resultWithoutMe )
	{
		// return an empty subset
		if( cur+1 == S.end() )
		{
			resultWithMe.push_back( vector<int>( 1, *cur ) );
			resultWithoutMe.push_back( vector<int>() );
			return *cur;
		}

		int nextVal = getSubsets( S, cur+1, resultWithMe, resultWithoutMe );
		const int resultWithMeCount = resultWithMe.size();
		const int resultWithoutMeCount = resultWithoutMe.size();

		// resultWithoutMe = resultWithSuccessor + resultWithoutSuccessor
		if( *cur != nextVal )
			resultWithoutMe.insert( resultWithoutMe.end(), resultWithMe.begin(), resultWithMe.end() );
		// else: resultWithoutMe = resultWithoutSuccessor

		// resultWithMe = me | (resultWithSuccessor + resultWithoutSuccessor)
		for( int i=0; i<resultWithMeCount; ++i )
			resultWithMe[i].insert( resultWithMe[i].begin(), *cur );

		vector<int> withMe( 1, *cur );
		for( int i=0; i<resultWithoutMeCount; ++i )
		{
			withMe.insert( withMe.end(), resultWithoutMe[i].begin(), resultWithoutMe[i].end() );
			resultWithMe.push_back( withMe );
			withMe.resize(1);
		}

		return *cur;
	}
};
