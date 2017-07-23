/*
 * 19_8.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

#include <vector>
#include <string>
#include <map>

using namespace std;

string trim( const string& word )
{
	int start = word.find_first_not_of(" /t/n/r");
	int stop = word.find_last_not_of(" /t/n/r") + 1;
	if( start>=0 && start<stop )
		return word.substr( start, stop );
	return word;
}

// assume: all words have been trimed
void countWord( map<string,int>& wordCount, const vector<string>& book )
{
	for( vector<string>::const_iterator it=book.begin(); it!=book.end(); ++it )
	{
		string word( trim(*it) );
		// to lower
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);

		if( wordCount.find(word)==wordCount.end() )
			wordCount.insert( make_pair(word,1) );
		else
			++wordCount[word];
	}
}

// assume: all words have been trimed
int getFrequency( const map<string,int>& wordCount, const string& word )
{
	string wordCopy( trim(word) );
	// to lower
	std::transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), ::tolower);
	map<string,int>::const_iterator it = wordCount.find(wordCopy);
	return ( it!=wordCount.end() ) ? it->second : 0;
}

///////////////// TEST /////////////////
#include <iostream>
int main()
{
	string book[] = { "I", "Love", "to", "be", "love", "by", "you" };
	map<string,int> wordCount;
	vector<string> bookVec( book, book+7 );
	countWord(wordCount, bookVec);
	cout << "getFrequency(love) = " << getFrequency(wordCount,"love") << endl; //2
	cout << "getFrequency(I) = " << getFrequency(wordCount,"I") << endl; //1
	cout << "getFrequency(he) = " << getFrequency(wordCount,"he") << endl; //0

	return 0;
}
