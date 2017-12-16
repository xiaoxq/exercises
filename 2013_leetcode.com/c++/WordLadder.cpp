/*
 * Problem: http://leetcode.com/onlinejudge#question_127
 */

#include <string>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		if( start==end )
			return 0;

		int steps = 2;
		const string empty;
		queue<string> processingQueue;
		set<string> visited;
		processingQueue.push( start );
		processingQueue.push( empty );
		visited.insert( start );

		while( true )
		{
			string& word = processingQueue.front();
			// finish one step
			if( word.empty() )
			{
				++steps;
				if( processingQueue.size()==1 )
					break;
				processingQueue.push( empty );
			}
			else
			{
				// generate every word of one edit distance
				for( int i=word.length()-1; i>=0; --i )
				{
					string oneEditDistanceWord(word);
					for( char c = 'a'; c<='z'; ++c )
					{
						oneEditDistanceWord[i] = c;
						// not in dict or has been visited
						if( dict.find(oneEditDistanceWord)==dict.end() || visited.find(oneEditDistanceWord)!=visited.end() )
							continue;

						// reach the end
						if( oneEditDistanceWord==end )
							return steps;

						processingQueue.push( oneEditDistanceWord );
						visited.insert( oneEditDistanceWord );
					}
				}
			}
			processingQueue.pop();
		}
		return 0;
	}
};
