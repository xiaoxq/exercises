/*
 * O(n!)
 *
 * 8_4.cpp
 *
 *  Created on: 2013-5-3
 *      Author: beet
 */

#include <string>
#include <vector>
using namespace std;

void getPermutations( string s, vector<string>& permutations )
{
	if( s.length()==1 )
		permutations.push_back(s);
	else if( !s.empty() )
	{
		// get the substring's permutations
		vector<string> sub_permutations;
		getPermutations( s.substr(1), sub_permutations );

		// insert the picked char 0 to every position of substring's permutations
		for( vector<string>::iterator sub_it=sub_permutations.begin();
				sub_it!=sub_permutations.end(); ++sub_it )
		{
			string sub_permutation(*sub_it);

			for( int j=0; j<=sub_it->length(); ++j )
			{
				string permutation(sub_permutation);
				permutation.insert(j, s.c_str(), 1);
				permutations.push_back(permutation);
			}
		}
	}
}

///////////////// TEST /////////////////
void test( const char* s )
{
	printf("=========\"%s\"'s permutations are=========\n", s);
	vector<string> permutations;
	getPermutations( s, permutations );
	for( vector<string>::iterator it=permutations.begin(); it!=permutations.end(); ++it )
		printf( "%s\n", it->c_str() );
}

int main()
{
	test( "" );
	test( "a" );
	test( "123" );
	test( "ab21" );
	return 0;
}
