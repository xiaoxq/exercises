/*
 * Problem: http://leetcode.com/onlinejudge#question_68
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> fullJustify(vector<string> &words, int L)
	{
		vector<string> result;

		int curLen = 0;
		vector<string>::const_iterator curLineStart = words.end();
		for( vector<string>::const_iterator it=words.begin(); it!=words.end(); ++it )
		{
			// init
			if( curLineStart == words.end() )
			{
				curLineStart = it;
				curLen = it->length();
			}
			else if( curLen + it->length() + 1 <= L )
			{
				curLen += it->length() + 1;
			}
			// finish one line
			else
			{
				const int wordNum = it-curLineStart;
				int spaceNum = L - curLen + wordNum - 1;

				string line( *curLineStart );

				if( wordNum==1 )
				{
					if( spaceNum>0 )
						line.append( spaceNum, ' ' );
				}
				else
				{
					const int avgSpaceNum = spaceNum / (wordNum-1);
					const int oneMoreSpaceNum = spaceNum % (wordNum-1);
					while( ++curLineStart != it )
					{
						if( oneMoreSpaceNum )
						{
							line.append( avgSpaceNum+1, ' ' );
							--oneMoreSpaceNum;
						}
						else
							line.append( avgSpaceNum, ' ' );
						line.append( *curLineStart );
						spaceNum -= avgSpaceNum;
					}
				}
				result.push_back( line );
				curLineStart = it;
				curLen = it->length();
			}
		}
		// last line
		if( curLineStart!=words.end() )
		{
			string line( *curLineStart );
			while( ++curLineStart != words.end() )
			{
				line.append( 1, ' ' );
				line.append( *curLineStart );
			}
			int tail = L - line.length();
			if( tail>0 )
				line.append( tail, ' ' );
			result.push_back( line );
		}
		return result;
	}
};
