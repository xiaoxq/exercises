/*
 * Problem: http://leetcode.com/onlinejudge#question_1
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> numbers_copy(numbers);
		vector<int> result(2);
		const int size = numbers_copy.size();

		sort( numbers_copy.begin(), numbers_copy.end() );

		// find the two sum's index of sorted array
		int left=0, right = size-1;
		while( left<right )
		{
			const int sum = numbers_copy[left] + numbers_copy[right];
			if( sum==target )
			{
				result[0] = numbers_copy[left];
				result[1] = numbers_copy[right];
				break;
			}
			( sum < target ) ? ++left : --right;
		}

		// find the left index
		for( int i=0; i<size; ++i )
		{
			if( numbers[i]==result[0] )
			{
				result[0] = i+1;
				break;
			}
		}

		// find the right index
		for( int i=size-1; i>=0; --i )
		{
			if( numbers[i]==result[1] )
			{
				result[1] = i+1;
				break;
			}
		}

		if( result[0]>result[1] )
		{
			int temp = result[0];
			result[0] = result[1];
			result[1] = temp;
		}

		return result;
	}
};
