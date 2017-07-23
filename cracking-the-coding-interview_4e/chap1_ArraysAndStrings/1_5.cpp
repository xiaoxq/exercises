/*
 * 1_5.cpp O(n)
 *
 *  Created on: 2013-3-29
 *      Author: beet
 *
 *  Modify in place?
 */

#include <string.h>
char* replaceSpace( char* str )
{
	// get right length, save some memories
	int len = strlen(str);
	for( int i=0; i<len; ++i )
		if( str[i]==' ' )
			len += 2;

	char* result = new char[len+1];
	result[len] = '\0';

	for( int r=0, w=0; w<len; ++r, ++w )
	{
		if( str[r]==' ' )
		{
			result[w] = '%';
			result[++w] = '2';
			result[++w] = '0';
		} else
			result[w] = str[r];
	}

	return result;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;
int main()
{
	char* test_cases[] = {
			"",
			" ",
			"abc",
			" abc",
			"abc ",
			" abc ",
			"abc abc",
			"abc  abc",
	};

	for( int i=sizeof(test_cases)/sizeof(test_cases[0])-1; i>=0; --i )
	{
		cout << "replaceSpace(" << test_cases[i] << ")="
				<< replaceSpace(test_cases[i]) << endl;
	}

	return 0;
}
