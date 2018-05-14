/*
 * 1_6.cpp O(N^2)
 *
 *  Created on: 2013-3-29
 *      Author: beet
 *
 *  Let's just rotate to right
 */

struct pixel
{
	char data[4];
};

void rotate( pixel** image, int N )
{
	for( int i=0; i+i<N; ++i )
	{
		for( int j=i; j<N-i-1; ++j )
		{
			pixel temp = image[i][j];
			image[i][j] = image[N-j-1][i];
			image[N-j-1][i] = image[N-i-1][N-j-1];
			image[N-i-1][N-j-1] = image[j][N-i-1];
			image[j][N-i-1] = temp;
		}
	}
}

///////////////// TEST /////////////////
#include <iostream>
using namespace std;

void printImage( pixel** image, int N )
{
	for( int i=0; i<N; ++i )
	{
		for( int j=0; j<N; ++j )
			cout << image[i][j].data << " ";
		cout << endl;
	}
}

void test(pixel** image, int N)
{
	cout << "=================" << endl << "rotate(" << endl;
	printImage( image, N );
	cout << ")=" << endl;
	rotate( image, N );
	printImage( image, N );
}

int main()
{
	// case 1
	pixel test_case1_line0[] = { "1","2","3" };
	pixel test_case1_line1[] = { "4","5","6" };
	pixel test_case1_line2[] = { "7","8","9" };

	pixel* test_case1[] = {
			test_case1_line0,
			test_case1_line1,
			test_case1_line2
	};
	test(test_case1,3);

	// case 2
	pixel test_case2_line0[] = { "1" };

	pixel* test_case2[] = {
			test_case2_line0,
	};
	test(test_case2,1);

	// case 3
	pixel test_case3_line0[] = { "1", "2" };
	pixel test_case3_line1[] = { "3", "4" };

	pixel* test_case3[] = {
			test_case3_line0,
			test_case3_line1,
	};
	test(test_case3,2);

	return 0;
}
