/*
 * Problem: http://leetcode.com/onlinejudge#question_31
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int> &num)
	{
		int incPos = num.size()-2;
		while( incPos>=0 && num[incPos]>=num[incPos+1] )
			--incPos;

		if( incPos<0 )
			sort( num.begin(), num.end() );
		else
		{
			// find the minimum in (incPos,end), which is greater than num[incPos]
			int decPos=num.size()-1;
			while( num[decPos]<=num[incPos] )
				--decPos;

			// swap
			int temp = num[incPos];
			num[incPos] = num[decPos];
			num[decPos] = temp;

			// sort the tail
			sort( num.begin()+incPos+1, num.end() );
		}
	}
};