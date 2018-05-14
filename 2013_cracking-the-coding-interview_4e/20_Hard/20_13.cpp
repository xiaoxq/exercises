/*
 * 20_13.cpp
 *
 *  Created on: 2013-6-7
 *      Author: beet
 */

#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// to make the parameters simple, just put some global data structures here
set<string> dict;
map<int, vector<string> > wordLenMap; // wordLength -> set<wordIndex>

// every position is in [0,range)
bool getNextPermutation( vector<int>& current, int range )
{
	const int len = current.size();
	for( vector<int>::reverse_iterator it=current.rbegin(); it!=current.rend(); ++it )
	{
		++ *it;
		if( *it<range )
			return true;
		*it = 0;
	}
	return false;
}

bool checkRect( const vector<string>& candiOnRow, const set<string>& candiOnColSet, const vector<int>& rowID )
{
	const int rectWidth = candiOnRow[0].length();
	const int rectHeight = rowID.size();

	// check on every col
	string col( rectHeight, ' ' );
	for( int i=0; i<rectWidth; ++i )
	{
		for( int j=0; j<rectHeight; ++j )
		{
			const string& word = dict[ candiOnRow[ rowID[j] ] ];
			col[j] = word[i];
		}
		if( candiOnColSet.find( col ) == candiOnColSet.end() )
			return false;
	}
	return true;
}

bool tryFillRect( vector<string>& result, const vector<string>& candiOnRow, const vector<string>& candiOnCol )
{
	const int rectWidth = candiOnRow[0].length();
	const int rectHeight = candiOnCol[0].length();
	const int rowPermutationRange = candiOnRow.size();
	const set<string> candiOnColSet( candiOnCol.begin(), candiOnCol.end() );

	vector<int> permutation( rectHeight, 0 );
	while( true )
	{
		if( checkRect(candiOnRow,candiOnColSet,permutation) )
			return true;
		if( !getNextPermutation(permutation, rowPermutationRange) )
			break;
	}
	return false;
}

void findLargestWordsRect(vector<string>& wordRow)
{
	// fill wordLenMap according to dict
	for( set<string>::const_iterator it=dict.begin(); it!=dict.end(); ++it )
	{
		int len = it->length();

		// add to wordLengthMap
		if( wordLenMap.find(len)==wordLenMap.end() )
			wordLenMap.insert( make_pair(len, vector<string>(1, *it)) );
		else
			wordLenMap[len].push_back( *it );
	}

	int maxi = 0;
	for( map<int, vector<string> >::const_reverse_iterator it=wordLenMap.rbegin(); it!=wordLenMap.rend(); ++it)
	{
		const int rectWidth = it->first;
		// has found the largest width
		if( maxi >= rectWidth*rectWidth )
			return;
		// no candidates with the length
		if( wordLenMap.find(rectWidth)==wordLenMap.end() )
			continue;

		// rectHeight<=rectWidth
		for( int rectHeight=rectWidth; rectHeight>0; --rectHeight )
		{
			// has found the largest height for current width
			if( maxi >= rectWidth * rectHeight )
				break;

			// no candidates with the length
			if( wordLenMap.find(rectHeight)==wordLenMap.end() )
				continue;

			if( tryFillRect(wordRow, wordLenMap[rectWidth], wordLenMap[rectHeight]) )
			{
				maxi = rectWidth * rectHeight;
				break;
			}
		}
	}
}
