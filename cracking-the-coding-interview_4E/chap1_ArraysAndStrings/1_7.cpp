/*
 * 1_7.cpp O(n^2)
 *
 *  Created on: 2013-3-30
 *      Author: beet
 */

#include <vector>
using namespace std;

// for easy
typedef int** Matrix;

void markZeros( Matrix m, int M, int N )
{
	vector<bool> zeroRows( M, false );
	vector<bool> zeroCols( N, false );

	for( int i=0; i<M; ++i )
		for( int j=0; j<N; ++j )
			if( m[i][j]==0 )
			{
				zeroRows[i] = true;
				zeroCols[j] = true;
			}

	for( int i=0; i<M; ++i )
		for( int j=0; j<N; ++j )
			if( zeroRows[i] || zeroCols[j] )
				m[i][j] = 0;
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;

void printMatrix( Matrix m, int M, int N )
{
	for( int i=0; i<M; ++i )
	{
		for( int j=0; j<N; ++j )
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void test( Matrix m, int M, int N )
{
	cout << "=================" << endl << "markZeros(" << endl;
	printMatrix( m, M, N );
	cout << ")=" << endl;
	markZeros( m, M, N);
	printMatrix( m, M, N );
}

int main()
{
	// case 1
	int test_case1_line0[] = { 1, 2, 3 };
	int test_case1_line1[] = { 4, 5, 6 };

	int* test_case1[] = {
			test_case1_line0,
			test_case1_line1
	};
	test( test_case1, 2, 3);

	// case 2
	int test_case2_line0[] = { 1 };

	int* test_case2[] = {
			test_case2_line0,
	};
	test( test_case2, 1, 1);

	// case 3
	int test_case3_line0[] = { 1, 2 };
	int test_case3_line1[] = { 3, 4 };

	int* test_case3[] = {
			test_case3_line0,
			test_case3_line1,
	};
	test( test_case3, 2, 2);

	// case 4
	int test_case4_line0[] = { 1, 2, 3 };
	int test_case4_line1[] = { 0, 0, 9 };

	int* test_case4[] = {
			test_case4_line0,
			test_case4_line1,
	};
	test( test_case4, 2, 3);

	// case 5
	int test_case5_line0[] = { 0 };

	int* test_case5[] = {
			test_case5_line0,
	};
	test( test_case5, 1, 1);

	// case 6
	int test_case6_line0[] = { 1, 2 };
	int test_case6_line1[] = { 0, 4 };

	int* test_case6[] = {
			test_case6_line0,
			test_case6_line1,
	};
	test( test_case6, 2, 2);

	return 0;
}
