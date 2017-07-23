/*
 * 1_8.cpp
 *
 *  Created on: 2013-3-30
 *      Author: beet
 */

#include <string.h>
#include <stdio.h>

bool isSubstring( char* s, char* sub )
{
	return strstr( s, sub ) != 0 ;
}

bool isRotation( char* s1, char* s2 )
{
	const int len1 = strlen(s1);
	if( len1 != strlen(s2) )
		return false;
	char* double_s1 = new char[ 2*len1 + 1 ];
	sprintf( double_s1, "%s%s", s1, s1 );

	return isSubstring( double_s1, s2 );
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;
int main()
{
	char* test_cases[] = {
			"", "a",
			"", "",
			"abc", "abcd",
			"abc", "abc",
			"abc", "cab",
			"abc", "bca",
	};

	for( int i=sizeof(test_cases)/sizeof(test_cases[0])-2; i>=0; i-=2 )
	{
		cout << "isRotation(" << test_cases[i] << "," << test_cases[i+1] << ")="
			<< (isRotation(test_cases[i],test_cases[i+1]) ? "true" : "false") << endl;
	}

	return 0;
}
