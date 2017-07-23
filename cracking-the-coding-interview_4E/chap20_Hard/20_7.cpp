/*
 * 20_7.cpp
 *
 *  Created on: 2013-5-21
 *      Author: beet
 */

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool strLenReverseCompare( const string& s1, const string& s2 )
{
	if( s1.length() != s2.length() )
		return s1.length() > s2.length();
	return s1 > s2;
}

bool isCompoundWord( const vector<string>& words, map<string,bool>& compoundMark, const string& word )
{
	map<string,bool>::iterator it = compoundMark.find( word );
	// has been checked
	if(it!=compoundMark.end())
		return it->second;

	// parse
	for( int i=word.length()-1; i>0; --i )
	{
		string leftPart = word.substr(0,i);
		bool isLeftPartAWord =
				binary_search( words.begin(), words.end(), leftPart, strLenReverseCompare )
				|| isCompoundWord(words,compoundMark,leftPart);
		if( !isLeftPartAWord )
			continue;

		string rightPart = word.substr(i);
		bool isRightPartAWord =
				binary_search( words.begin(), words.end(), rightPart, strLenReverseCompare )
				|| isCompoundWord(words,compoundMark,rightPart);
		if( !isRightPartAWord )
			continue;

		// is compound word
		compoundMark.insert( make_pair( word, true ) );
		return true;
	}

	// is not compound word
	compoundMark.insert( make_pair( word, false ) );
	return false;
}

string findLongestCompoundWord( vector<string>& words )
{
	sort( words.begin(), words.end(), strLenReverseCompare );

	map<string,bool> compoundMark;
	for(vector<string>::const_iterator it=words.begin(); it!=words.end(); ++it)
		if( isCompoundWord(words, compoundMark, *it) )
			return *it;
	return "";
}

///////////////// TEST /////////////////
int main()
{
	string words[] = { "test", "tester", "testertest", "testing", "testingtester", "testtestertestin", "testtestertesting" };
	vector<string> wordsVec( words, words+6 );
	cout << findLongestCompoundWord(wordsVec) << " is the longest compound word" << endl; // testingtester
	vector<string> wordsVec2( words, words+7 );
	cout << findLongestCompoundWord(wordsVec2) << " is the longest compound word" << endl; // testtestertesting
	return 0;
}
