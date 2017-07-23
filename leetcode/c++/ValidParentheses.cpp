/*
 * Problem: http://leetcode.com/onlinejudge#question_20
 */

#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> leftBrackets;
		for( string::const_iterator it=s.begin(); it!=s.end(); ++it )
		{
			if( *it=='(' || *it=='[' || *it=='{' )
			{
				leftBrackets.push( *it );
			}
			else if( *it==')' )
			{
				if( leftBrackets.empty() || leftBrackets.top()!='(' )
					return false;
				leftBrackets.pop();
			}
			else if( *it==']' )
			{
				if( leftBrackets.empty() || leftBrackets.top()!='[' )
					return false;
				leftBrackets.pop();
			}
			else if( *it=='}' )
			{
				if( leftBrackets.empty() || leftBrackets.top()!='{' )
					return false;
				leftBrackets.pop();
			}
		}
		return leftBrackets.empty();
	}
};
