/*
 * 9_4.cpp
 *
 *  Created on: 2013-5-5
 *      Author: beet
 */

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
// for simple, we assert that no io error will occur

// write a chunk
void writeChunk( const char* filename, vector<string>& data )
{
	ofstream fout( filename );
	//assert(fout);

	cout << "Writing chunk file: " << filename << endl;
	for( vector<string>::iterator it=data.begin(); it!=data.end(); ++it )
		fout << *it << endl;
	fout.close();
}

// sort file chunk by chunk, O(nlogm), where m is the chunk lines
void chunkSort(const char* filename, vector<string>& chunkfiles)
{
	// 64MB, we can also separate chunks by line size
	const unsigned int ChunkSize = 1<<26;

	ifstream fin(filename);
	//assert(fin);

	vector<string> chunk;
	unsigned int currentSize = 0;
	string currentLine;
	int chunkID = 0;

	while( getline(fin,currentLine) )
	{
		// finish a chunk: sort, write and clear
		if( currentSize+currentLine.length() > ChunkSize )
		{
			sort( chunk.begin(), chunk.end() );
			ostringstream ss;
			ss << "sortedchunk_" << chunkID++ << ".txt";
			writeChunk( ss.str().c_str(), chunk );
			chunkfiles.push_back( ss.str() );
			chunk.clear();
			currentSize = 0;
		}

		currentSize += currentLine.length();
		chunk.push_back( currentLine );
	}
	// the last chunk
	if( !chunk.empty() )
	{
		sort( chunk.begin(), chunk.end() );
		ostringstream ss;
		ss << "sortedchunk_" << chunkID << ".txt";
		writeChunk( ss.str().c_str(), chunk );
		chunkfiles.push_back( ss.str() );
	}
	fin.close();
}

// sort 2 chunks in every pass
string twoWayMerge( vector<string>& chunkfiles )
{
	for( int i=1; i<chunkfiles.size(); i+=2 )
	{
		ifstream fin1(chunkfiles[i-1].c_str());
		ifstream fin2(chunkfiles[i].c_str());
		ostringstream ss;
		ss << "mergedchunk_" << i/2 << ".txt";
		ofstream fout( ss.str().c_str() );
		//assert( fin1 && fin2 && fout );

		cout << "Merge file " << chunkfiles[i-1] << " and " << chunkfiles[i]
		     << " into " << ss.str() << endl;

		string s1,s2;
		getline(fin1,s1);
		getline(fin2,s2);
		while( fin1 && fin2 )
		{
			if( s1<s2 )
			{
				fout << s1 << endl;
				getline(fin1,s1);
			}
			else
			{
				fout << s2 << endl;
				getline(fin2,s2);
			}
		}

		while( fin1 )
		{
			fout << s1 << endl;
			getline(fin1,s1);
		}
		while( fin2 )
		{
			fout << s2 << endl;
			getline(fin2,s2);
		}
		fin1.close();
		fin2.close();
		fout.close();
		// add the new merged file
		chunkfiles.push_back(ss.str());
	}
	if(chunkfiles.size()>0)
		return chunkfiles[ chunkfiles.size()-1 ];
	return "";
}

string externalSort(const char* filename)
{
	vector<string> chunkfiles;
	chunkSort(filename, chunkfiles);
	return twoWayMerge(chunkfiles);
}

///////////////// TEST /////////////////
#include <stdlib.h>
void genRandomStringFile( const char* filename, unsigned int lineSize )
{
	const char chars[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	const int charsLen = strlen(chars);
	const int lineLen = 64;
	srand( (unsigned int)( time(NULL) ));

	cout << "Generate random string file..." << endl;
	int linePercent = lineSize / 100;
	ofstream fout(filename);
	//assert(fout);
	while(lineSize--)
	{
		// random length
		int length = rand() % lineLen;
		while( length==0 )
			length = rand() % lineLen;
		while( length-- )
		{
			// random char
			int pos = rand() % charsLen;
			fout << chars[pos];
		}
		fout << endl;
		if( lineSize % linePercent==0 )
			cout << lineSize << " lines remain" << endl;
	}
	fout.close();
}

int main(int argc, char* argv[])
{
	const char* input = "input.txt";
	if( argc==1 || strcmp(argv[1], "--help") || strcmp(argv[1], "-h") )
	{
		cout << "Usage: " << argv[0] << " <line size>" << endl
				<< "\tThe program will generate a file with <line size> lines"
				"of random strings, and sort it." << endl;
		return 0;
	}

	int lineSize = atoi(argv[1]);
	// default size is 512MB
	if(lineSize<=0)
		lineSize = 1<<24; // (averagely 32B/line) * (16M lines)

	genRandomStringFile(input, lineSize);
	string output = externalSort(input);

	cout << "The result is " << output << endl;
	return 0;
}
