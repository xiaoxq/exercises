/*
 * 5_2.cpp
 *
 *  Created on: 2013-4-23
 *      Author: beet
 */

#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

void printIntToBinary( const char* intStr, vector<char>& ret )
{
	const char* readPtr = intStr;
	// skip any non-digit chars, such as +/-
	while( *readPtr < '0' || *readPtr > '9' )
		++readPtr;

	int value = atoi(readPtr);
	if( value==0 )
		ret.push_back( '0' );
	else
	{
		while(value!=0)
		{
			ret.insert( ret.begin(), (value%2) + '0' );
			value >>= 1;
		}
	}
	// keep any non-digit chars, such as +/-
	while( (--readPtr) >=  intStr )
		ret.insert( ret.begin(), *readPtr );
}

void printDecimalToBinary( const char* decimalStr )
{
	vector<char> ret;
	// print the integer part
	printIntToBinary(decimalStr, ret);

	const char* dot = strchr( decimalStr, '.' );
	if(dot>0)
	{
		ret.push_back('.');

		int decimalLen = strlen(dot+1);
		int decimalToInt = atoi(dot+1);
		if(decimalToInt==0)
			ret.push_back('0');
		else
		{
			// base = 0.5 * power(10, decimalLen), decimalLen>0
			int base = 5;
			while(--decimalLen)
				base *= 10;

			while( decimalToInt>0 )
			{
				if( decimalToInt>=base )
				{
					ret.push_back('1');
					decimalToInt -= base;
				}
				else
					ret.push_back('0');

				// error
				if(decimalToInt>0 && base%2!=0)
				{
					printf("error\n");
					return;
				}
				base >>= 1;
			}
		}
	}
	ret.push_back('\0');
	printf( "%s\n", &(ret[0]) );
}

///////////////// TEST /////////////////
int main()
{
	printDecimalToBinary( "0" ); // 0
	printDecimalToBinary( "-0" ); // -0
	printDecimalToBinary( "+0" ); // +0
	printDecimalToBinary( "0.5" ); // 0.1
	printDecimalToBinary( "1.5" ); // 1.1
	printDecimalToBinary( "-2.75" ); //-10.11
	printDecimalToBinary( "7.875" ); // 111.111
	printDecimalToBinary( "-2.375" ); // -10.011
	printDecimalToBinary( "2.3333" ); // error
}
