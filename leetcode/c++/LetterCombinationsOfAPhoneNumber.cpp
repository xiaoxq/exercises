/*
 * Problem: http://leetcode.com/onlinejudge#question_17
 */

#include <vector>
#include <string>
using namespace std;

const string digits2char[10] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> result;
		if( digits.empty() )
		{
			result.push_back("");
			return result;
		}

		const int len = digits.length();
		vector<int> scanningIndex( len, 0 );
		do
		{
			// record a solution
			string solution;
			for( int i=0; i<len; ++i )
			{
				if( digits[i]!='1' )
				{
					solution.append( 1, digits2char[ digits[i]-'0' ][ scanningIndex[i] ] );
				}
			}
			result.push_back( solution );
		} while( incScanningIndex(digits,scanningIndex) );

		return result;
	}
private:
	bool incScanningIndex( const string& digits, vector<int>& scanningIndex )
	{
		const int len = digits.length();
		for( int i=0; i<len; ++i )
		{
			++scanningIndex[i];
			if( scanningIndex[i] < digits2char[ digits[i]-'0' ].length() )
				return true;
			scanningIndex[i] = 0;
		}
		return false;
	}
};
