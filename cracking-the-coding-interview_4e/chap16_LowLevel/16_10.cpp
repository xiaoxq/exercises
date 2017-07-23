/*
 * 16_10.cpp
 *
 *  Created on: 2013-5-18
 *      Author: beet
 */

#include <malloc.h>

#define NULL 0

/*
 * [ptrToRow0] [ptrToRow1] [ptrToRow2]
 * [Row0]
 * [Row1]
 * [Row2]
 */
int** My2DAlloc(int rows, int cols)
{
	size_t headerSize = sizeof(int*) * rows;
	size_t dataSize = sizeof(int) * rows * cols;

	int** ptrHeader = (int**)malloc(headerSize+dataSize);
	int* ptrData = (int*)(ptrHeader+rows);
	for( int i=0; i<rows; ++i )
		ptrHeader[i] = ptrData + i*cols;
	return ptrHeader;
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int rows = 2, cols = 2;
	int** mat = My2DAlloc(rows,cols);
	printf( "%x\n", mat );
	for( int i=0; i<rows; ++i )
	{
		for( int j=0; j<cols; ++j )
			printf( "%x ", &(mat[i][j]) );
		printf("\n");
	}

	return 0;
}
