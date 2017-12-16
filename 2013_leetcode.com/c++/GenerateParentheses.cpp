/*
 * Problem: http://leetcode.com/onlinejudge#question_22
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		printValidParenthesis( "", n, n, result );
		return result;
	}

private:
	void printValidParenthesis( string prefix, int open_remain, int close_remain, vector<string>& result )
	{
		// reach the end
		if( open_remain==0 && close_remain==0 )
		{
			result.push_back( prefix );
			return;
		}

		// open one
		if( open_remain>0 )
			printValidParenthesis( prefix+"(", open_remain-1, close_remain, result );

		// close one
		if( close_remain>open_remain )
			printValidParenthesis( prefix+")", open_remain, close_remain-1, result );
	}
};
