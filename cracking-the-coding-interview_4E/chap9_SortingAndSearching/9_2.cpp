/*
 * 9_2.cpp
 *
 *  Created on: 2013-5-5
 *      Author: beet
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compareStrByAnagrams( string s1, string s2 )
{
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	return s1<s2;
}

void sortByAnagrams( vector<string>& strs )
{
	sort( strs.begin(), strs.end(), compareStrByAnagrams );
}

///////////////// TEST /////////////////
#include <iostream>
int main()
{
	vector<string> strs;
	strs.push_back( "aabbcc" );
	strs.push_back( "abbcc" );
	strs.push_back( "abcabc" );
	strs.push_back( "c" );
	strs.push_back( "ccbbaa" );
	strs.push_back( "ccbbaaa" );
	strs.push_back( "cbacba" );

	sortByAnagrams(strs);
	for( vector<string>::iterator it=strs.begin(); it!=strs.end(); ++it )
		cout << *it << endl;
	return 0;
}
