/*
 * 1_1.cpp O(n)
 *
 *  Created on: 2013-3-29
 *      Author: beet
 */

#include <string.h>
#include <vector>
using namespace std;

bool isAllUniq( char* str )
{
	vector<bool> showup( 0x100, false );
	for( int i=0; str[i]!=0; ++i )
	{
		unsigned int index = (unsigned char) str[i];
		if( showup[index] )
			return false;
		showup[index] = true;
	}
	return true;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;
int main()
{
	char* test_cases[] = {
			"",
			"a",
			"abcdef",
			"abcdefa",
			"aaaaaa"
	};

	for( int i=sizeof(test_cases)/sizeof(test_cases[0])-1; i>=0; --i )
	{
		cout << "isAllUniq(" << test_cases[i] << ")="
			<< (isAllUniq(test_cases[i]) ? "true" : "false") << endl;
	}

	return 0;
}
