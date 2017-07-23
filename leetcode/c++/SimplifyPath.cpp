/*
 * Problem: http://leetcode.com/onlinejudge#question_71
 */

#include <string>
using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		vector<string> pathes;

		const int len = path.length();
		string cur;
		for( int i=0; i<len; ++i )
		{
			// reach a split
			if( path[i]=='/' )
			{
				// to parent if possible
				if( cur==".." )
				{
					if( !pathes.empty() )
						pathes.pop_back();
				} else if( !cur.empty() && cur!="." )
					pathes.push_back( cur );
				cur.clear();
			}
			else
				cur.append( 1, path[i] );
		}
		// to parent if possible
		if( cur==".." )
		{
			if( !pathes.empty() )
				pathes.pop_back();
		}
		else if( !cur.empty() && cur!="." )
			pathes.push_back( cur );

		string result;
		for( vector<string>::const_iterator it=pathes.begin(); it!=pathes.end(); ++it )
		{
			result.append( 1, '/' );
			result.append( *it );
		}
		return ( !result.empty() ) ? result : "/";
	}
};
