/*
 * Problem: http://leetcode.com/onlinejudge#question_49
 */

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string> &strs)
	{
		map<string, vector<int> > anaStrIDMap;
		const int num = strs.size();
		for( int i=0; i<num; ++i )
		{
			string id( strs[i] );
			sort( id.begin(), id.end() );

			map<string, vector<int> >::iterator it = anaStrIDMap.find(id);
			if( it==anaStrIDMap.end() )
				it = anaStrIDMap.insert( make_pair(id,vector<int>()) ).first;
			it->second.push_back( i );
		}

		vector<string> result;
		for( map<string, vector<int> >::iterator it=anaStrIDMap.begin();
				it!=anaStrIDMap.end(); ++it)
		{
			vector<int>& sameIdStrs = it->second;
			if( sameIdStrs.size()>1 )
			{
				for( vector<int>::iterator itStrIndex = sameIdStrs.begin();
						itStrIndex != sameIdStrs.end(); ++itStrIndex )
					result.push_back( strs[ *itStrIndex ] );
			}
		}
		return result;
	}
};
