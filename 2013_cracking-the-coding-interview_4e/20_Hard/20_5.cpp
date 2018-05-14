/*
 * 20_5.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

#include <vector>
#include <string>
using namespace std;

int minDistOfWords( const vector<string>& words, const string& word1, const string& word2 )
{
	int size = words.size();
	int minDist = size;

	int lastWord1Pos = -size;
	int lastWord2Pos = -size;
	for( int i=0; i<size; ++i )
	{
		if( words[i]==word1 )
		{
			int newDist = i-lastWord2Pos;
			if( newDist < minDist )
				minDist = newDist;
			lastWord1Pos = i;
		}
		else if( words[i]==word2 )
		{
			int newDist = i-lastWord1Pos;
			if( newDist < minDist )
				minDist = newDist;
			lastWord2Pos = i;
		}
	}

	return minDist;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	string words[] = { "a", "b", "c", "d", "e", "f", "g", "b", "c", "d" };
	vector<string> wordsVec( words, words+10 );

	string word1 = "a", word2 = "d";
	printf( "minDistOfWords(%s,%s)=%d\n", word1.c_str(), word2.c_str(), minDistOfWords(wordsVec,word1,word2) );//3
	word1 = "c", word2 = "g";
	printf( "minDistOfWords(%s,%s)=%d\n", word1.c_str(), word2.c_str(), minDistOfWords(wordsVec,word1,word2) );//2

	return 0;
}
