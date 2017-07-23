/*
 * 1_2.cpp O(2n)
 *
 *  Created on: 2013-3-29
 *      Author: beet
 *
 *  Write over the source string, or make a reversed copy?
 */

#include <string.h>

void reverse( char* str )
{
	int left = 0;
	int right = strlen(str) - 1;
	while( left<right )
	{
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		++ left;
		-- right;
	}
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;
int main()
{
	char test_case0[] = "";
	char test_case1[] = "a";
	char test_case2[] = "abcdef";
	char test_case3[] = "abccabc";
	char test_case4[] = "abcdefedcba";
	char* test_cases[] = { test_case0,test_case1,test_case2,test_case3,test_case4 };

	for( int i=sizeof(test_cases)/sizeof(test_cases[0])-1; i>=0; --i )
	{
		cout << "reverse(" << test_cases[i] << ")=";
		reverse(test_cases[i]);
		cout << test_cases[i] << endl;
	}

	return 0;
}
