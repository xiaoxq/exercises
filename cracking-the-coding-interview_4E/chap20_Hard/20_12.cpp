/*
 * 20_12.cpp
 *
 *  Created on: 2013-6-2
 *      Author: beet
 */

struct SubMatrix
{
	int LeftTopX, LeftTopY;
	int RightBottomX, RightBottomY;
};

// [(i,j), (k,w)]
inline int getSumIJtoKW(int** sum00toij, int i, int j, int k, int w)
{
	return sum00toij[k][w]-sum00toij[i-1][w]-sum00toij[k][j-1]+sum00toij[i-1][j-1];
}

int getLargestSum( const int** matrix, const int N, SubMatrix& result )
{
	// init
	int** sum00toij = new int*[N];
	for( int i=0; i<N; ++i )
	{
		sum00toij[i] = new int[N];
		int currentLineSum = 0;
		for( int j=0; j<N; ++j )
		{
			currentLineSum += matrix[i][j];
			sum00toij[i][j] = (i==0) ? currentLineSum : currentLineSum + sum00toij[i-1][j];
		}
	}

	// find the maxi
	int maxi = 0;
	for( int i=0; i<N; ++i )
		for( int j=0; j<N; ++j )
			for( int k=0; k<N; ++k )
				for( int w=0; w<N; ++w )
				{
					int temp = getSumIJtoKW( sum00toij, i, j, k, w );
					if(temp>maxi)
					{
						maxi = temp;
						result.LeftTopX = i;
						result.LeftTopY = j;
						result.RightBottomX = k;
						result.RightBottomY = w;
					}
				}

	// release
	for( int i=0; i<N; ++i )
		delete[] sum00toij[i];
	delete[] sum00toij;

	return maxi;
}
