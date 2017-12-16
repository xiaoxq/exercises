/*
 * The official output is not right
 *
 * 8_5.cpp
 *
 *  Created on: 2013-5-3
 *      Author: beet
 */

#include <string>
#include <iostream>
using namespace std;

void printValidParenthesis( string prefix, int open_remain, int close_remain )
{
	// reach the end
	if( open_remain==0 && close_remain==0 )
	{
		cout << prefix << endl;
		return;
	}

	// open one
	if( open_remain>0 )
		printValidParenthesis( prefix+"(", open_remain-1, close_remain );

	// close one
	if( close_remain>open_remain )
		printValidParenthesis( prefix+")", open_remain, close_remain-1 );
}

// wrapper
void printValidParenthesis( int pairs_num )
{
	printValidParenthesis( "", pairs_num, pairs_num );
}

///////////////// TEST /////////////////
int main()
{
	printValidParenthesis(0); //""
	cout << "=======" << endl;
	printValidParenthesis(1); //"()"
	cout << "=======" << endl;
	printValidParenthesis(3); //"((())), (())(), ()(()), ()()(), (()())"
	return 0;
}
