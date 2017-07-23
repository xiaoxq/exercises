/*
 * 9_6.cpp
 *
 *  Created on: 2013-5-6
 *      Author: beet
 */

#include <vector>
using namespace std;

bool findInSortedMatrix( const vector< vector<int> >& matrix, int target,
		int left, int right, int top, int bottom,
		int& resultI, int& resultJ )
{
	// reach the end
	if( left+1==right && top+1==bottom )
	{
		if( matrix[top][left]==target )
		{
			resultI = top;
			resultJ = left;
			return true;
		}
		return false;
	}
	if( left>=right || top>=bottom )
		return false;

	int middleI = (top+bottom) / 2;
	int middleJ = (left+right) / 2;

	// top right and bottom left blocks
	if( findInSortedMatrix( matrix,target, middleJ, right, top, middleI, resultI, resultJ)
		|| findInSortedMatrix( matrix,target, left, middleJ, middleI, bottom, resultI, resultJ) )
		return true;
	// bottom right block
	if( target >= matrix[middleI][middleJ] )
		return findInSortedMatrix( matrix,target, middleJ, right, middleI, bottom, resultI, resultJ);
	// top left block
	return findInSortedMatrix( matrix,target, left, middleJ, top, middleI, resultI, resultJ);
}

///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	int values[] = {
		1,	3,	5,	7,	9,
		2,	4,	6,	8,	10,
		11,	12,	13,	14,	15,
		16,	17,	18,	19,	20,
		21,	22,	24,	25,	26
	};
	vector< vector<int> > matrix;
	matrix.push_back( vector<int>( values, values+5 ) );
	matrix.push_back( vector<int>( values+5, values+10 ) );
	matrix.push_back( vector<int>( values+10, values+15 ) );
	matrix.push_back( vector<int>( values+15, values+20 ) );
	matrix.push_back( vector<int>( values+20, values+25 ) );
	int resultI, resultJ, target;
	// (0,1)
	target = 3;
	if(!findInSortedMatrix(matrix,target,0,5,0,5,resultI,resultJ))
		resultI = resultJ = -1;
	printf( "findInSortedMatrix(%d)=(%d,%d)\n", target, resultI, resultJ);
	// (3,2)
	target = 18;
	if(!findInSortedMatrix(matrix,target,0,5,0,5,resultI,resultJ))
		resultI = resultJ = -1;
	printf( "findInSortedMatrix(%d)=(%d,%d)\n", target, resultI, resultJ);
	// (4,4)
	target = 26;
	if(!findInSortedMatrix(matrix,target,0,5,0,5,resultI,resultJ))
		resultI = resultJ = -1;
	printf( "findInSortedMatrix(%d)=(%d,%d)\n", target, resultI, resultJ);
	// (-1,-1)
	target = 23;
	if(!findInSortedMatrix(matrix,target,0,5,0,5,resultI,resultJ))
		resultI = resultJ = -1;
	printf( "findInSortedMatrix(%d)=(%d,%d)\n", target, resultI, resultJ);
	return 0;
}
