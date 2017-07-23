/*
 * Problem: http://leetcode.com/onlinejudge#question_131
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<vector<string> > partition(string s)
	{
		vector<vector<string> > result;
		vector<string> prefix;
		writeResult(s,0,result,prefix);
		return result;
	}
private:
	void writeResult( const string& s, int index, vector<vector<string> >& result, vector<string>& prefix )
	{
		const int len = s.length();
		for( int i=1; index+i<len; ++i )
		{
			// check if s[index:index+i] is palindrome
			if( !isPalindrome( s, index, index+i-1 ) )
				continue;
			prefix.push_back( s.substr( index, i ) );
			writeResult( s, index+i, result, prefix );
			prefix.pop_back();
		}

		if( index<len && isPalindrome(s,index,len-1) )
		{
			prefix.push_back( s.substr( index ) );
			result.push_back( prefix );
			prefix.pop_back();
		}
	}

	bool isPalindrome( const string& s, int left, int right )
	{
		while( left<right )
		{
			if( s[left++]!=s[right--] )
				return false;
		}
		return true;
	}
};
