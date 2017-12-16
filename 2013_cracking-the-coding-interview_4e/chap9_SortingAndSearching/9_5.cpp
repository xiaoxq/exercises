/*
 * 9_5.cpp
 *
 *  Created on: 2013-5-5
 *      Author: beet
 */

#include <vector>
#include <string>
using namespace std;

// find in [left,right)
int findString( const vector<string>& strs, const string& target)
{
	int left = 0;
	int right = strs.size();
	while( left<right )
	{
		// trim
		while( left<right && strs[left]=="" )
			++left;
		while( left<right && strs[right-1]=="" )
			--right;

		// out of the range
		if( left>=right || strs[left]>target || strs[right-1]<target )
			return -1;

		int middle = (left+right)/2;
		// trim
		while( strs[middle]=="" )
			++middle;
		if( strs[middle]==target )
			return middle;
		strs[middle]<target ? left = middle+1 : right = (left+right)/2;
	}
	return -1;
}


///////////////// TEST /////////////////
#include <stdio.h>
int main()
{
	char* array[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	vector<string> vec(array,array+13);
	printf( "findString(%s)=%d\n", "ball", findString(vec,"ball") ); //4
	printf( "findString(%s)=%d\n", "ballcar", findString(vec,"ballcar") ); //-1
}
