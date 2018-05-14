/*
 * 20_10.cpp
 *
 *  Created on: 2013-5-22
 *      Author: beet
 */

#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
using namespace std;

// assume that all words are in lower case
bool transformWords( list<string>& path, const string& start, const string& stop, const set<string>& dict )
{
	if( start==stop )
		return true;

	map<string,string> backtrackMap;
	queue<string> processingQueue;
	set<string> visited;
	processingQueue.push(start);
	visited.insert( start );

	while( !processingQueue.empty() )
	{
		string& word = processingQueue.front();
		// generate every word of one edit distance
		for( int i=word.length()-1; i>=0; --i )
		{
			string oneEditDistanceWord(word);
			for( char c = 'a'; c<='z'; ++c )
			{
				oneEditDistanceWord[i] = c;
				// not in dict or has been visited
				if( dict.find(oneEditDistanceWord)==dict.end()
						|| visited.find(oneEditDistanceWord)!=visited.end() )
					continue;

				// reach the end
				if( oneEditDistanceWord==stop )
				{
					while( word!=start )
					{
						path.push_front(word);
						word = backtrackMap[word];
					}
					return true;
				}

				// to be processed
				backtrackMap.insert( make_pair(oneEditDistanceWord, word) );
				processingQueue.push( oneEditDistanceWord );
				visited.insert( oneEditDistanceWord );

				// revert the transform
				oneEditDistanceWord[i] = word[i];
			}
		}
		processingQueue.pop();
	}
	return false;
}

///////////////// TEST /////////////////
#include <iostream>
int main()
{
	string dict[] = { "damp", "dame", "lamp", "lamb", "limp", "lisp", "lime", "like", "look" };
	set<string> dictSet( dict, dict+9 );
	list<string> path;
	string start="damp", stop="like";
	if( transformWords(path,"damp","like",dictSet)  )
	{
		cout << start << " -> ";
		for( list<string>::const_iterator it=path.begin(); it!=path.end(); ++it )
			cout << *it << " -> ";
		cout << stop << endl;
	}
	else
		cout << "Cannot transform " << start << " to " << stop << endl;

	return 0;
}
