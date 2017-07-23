/*
 * 1_3.cpp O(n^2)
 *
 *  Created on: 2013-3-29
 *      Author: beet
 *
 *  Could I use a array with fixed size?
 */


void uniq( char* str )
{
	int r=0, w=0;
	while( str[r]!='\0' )
	{
		bool isDuplicate = false;
		for( int i=0; i<w; ++i )
		{
			if( str[i]==str[r] )
			{
				isDuplicate = true;
				break;
			}
		}
		if( !isDuplicate )
			str[w++] = str[r];
		++ r;
	}
	// mark the ending
	str[w] = '\0';
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;
int main()
{
	char test_case0[] = "";
	char test_case1[] = "a";
	char test_case2[] = "abcdef";
	char test_case3[] = "abcdefedcba";
	char test_case4[] = "aabbccddeeffeeddccbbaa";
	char* test_cases[] = { test_case0,test_case1,test_case2,test_case3,test_case4 };

	for( int i=sizeof(test_cases)/sizeof(test_cases[0])-1; i>=0; --i )
	{
		cout << "uniq(" << test_cases[i] << ")=";
		uniq(test_cases[i]);
		cout << test_cases[i] << endl;
	}

	return 0;
}
