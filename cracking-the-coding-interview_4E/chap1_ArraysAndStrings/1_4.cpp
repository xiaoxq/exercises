/*
 * 1_4.cpp O(n)
 *
 *  Created on: 2013-3-29
 *      Author: beet
 *
 *	What is anagram??
 *  Is null string an anagrams?
 */

#include <string.h>
bool isAnagrams( char* str1, char* str2 )
{
	const int len = strlen(str1);
	if( strlen(str2) != len )
		return false;

	for( int i=0; i<len; ++i )
		if( str1[i] != str2[len-1-i] )
			return false;

	return true;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;
int main()
{
	char* test_cases[] = {
			"", "a",
			"", "",
			"aa", "aa",
			"ab", "ab",
			"ab", "ba",
			"abba", "abba",
			"abcd", "dcba",
			"abcd", "dcab"
	};

	for( int i=sizeof(test_cases)/sizeof(test_cases[0])-2; i>=0; i-=2 )
	{
		cout << "isAnagrams(" << test_cases[i] << "," << test_cases[i+1] << ")="
			<< (isAnagrams(test_cases[i],test_cases[i+1]) ? "true" : "false") << endl;
	}

	return 0;
}
