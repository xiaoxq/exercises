/*
 * 13_1.cpp
 *
 *  Created on: 2013-5-17
 *      Author: beet
 */

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void printLastKLine( char* filename, int K )
{
	ifstream fin(filename);
	vector<string> lastKLine(K);

	int lineNum=0;
	// read
	if(!fin)
		return;

	// write in circle
	while( getline(fin, lastKLine[lineNum%K]) )
		++lineNum;
	fin.close();

	// set bound
	int start = lineNum-K, end=lineNum;
	if( start<0 )
		start = 0;

	// print
	for( int i=start; i<end; ++i )
		cout << lastKLine[ i % K ] << endl;
}
