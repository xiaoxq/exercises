/*
 * Problem: http://leetcode.com/onlinejudge#question_126
 */

#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		map<string, set<string> > successors;
		set<string> curLevel, nextLevel;

		curLevel.insert( start );
		dict.erase( start );

		int level = 0;
		bool found = (start==end);
		while( !curLevel.empty() && !found )
		{
			++ level;
			for( set<string>::const_iterator it=curLevel.begin(); it!=curLevel.end(); ++it )
			{
				set<string> mySuccessor;
				for( int i=it->length()-1; i>=0; --i )
				{
					string oneEditDistanceWord(*it);
					for( char c = 'a'; c<='z'; ++c )
					{
						oneEditDistanceWord[i] = c;
						if( dict.find( oneEditDistanceWord ) == dict.end() )
							continue;
						mySuccessor.insert( oneEditDistanceWord );
						nextLevel.insert( oneEditDistanceWord );
						if( oneEditDistanceWord == end )
							found = true;
					}
				}
				successors.insert( make_pair(*it, mySuccessor) );
			}
			for( set<string>::const_iterator it=nextLevel.begin(); it!=nextLevel.end(); ++it )
				dict.erase( *it );

			curLevel.swap( nextLevel );
			nextLevel.clear();
		}

		vector<vector<string> > result;
		if( found )
		{
			vector<string> prefix( 1, start );
			writeResult( successors, end, prefix, result, level );
		}
		return result;
	}

private:
	void writeResult( map<string, set<string> >& successors, string& end, vector<string>& prefix,
			vector<vector<string> >& result, int level )
	{
		const string& tail = *(prefix.rbegin());
		const set<string>& mySuccessor = successors[tail];
		// reach the end
		if( level==1 )
		{
			if( mySuccessor.find( end ) != mySuccessor.end() )
			{
				prefix.push_back( end );
				result.push_back( prefix );
				prefix.pop_back();
			}
			return;
		}

		for( set<string>::const_iterator it=mySuccessor.begin(); it!=mySuccessor.end(); ++it )
		{
			prefix.push_back( *it );
			writeResult( successors, end, prefix, result, level-1 );
			prefix.pop_back();
		}
	}
};
