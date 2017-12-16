/*
 * Problem: http://leetcode.com/onlinejudge#question_89
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> result;
		set<int> used;
		int current = 0;
		do
		{
			used.insert( current );
			result.push_back( current );
			current = changeOneBit(current, used, n);
		} while( current );

		return result;
	}
private:
	int changeOneBit( int current, const set<int>& used, int n )
	{
		for( int i=0; i<n; ++i )
		{
			int afterChange = current ^ (1<<i);
			if( used.find( afterChange ) == used.end() )
				return afterChange;
		}
		// invalid
		return 0;
	}
};
