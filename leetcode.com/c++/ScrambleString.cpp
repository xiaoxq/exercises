/*
 * Problem: http://leetcode.com/onlinejudge#question_87
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool isScramble(string s1, string s2)
	{
		const int len = s1.length();
		if( s2.length() != len )
			return false;

		return isScramble(s1,0,s2,0,len);
	}
private:
	bool isScramble(const string& s1, const int index1, const string& s2, const int index2, const int len)
	{
			vector<int> charCount( 26, 0 );
			for( int i=0; i<len; ++i )
			{
				++charCount[ s1[index1+i]-'a' ];
				--charCount[ s2[index2+i]-'a' ];
			}

			for( int i=0; i<26; ++i )
				if( charCount[i]!=0 )
					return false;

			if( len <= 2 )
				return true;

			for( int i=1; i<len; ++i )
			{
				if( isScramble(s1,index1,s2,index2,i) && isScramble(s1,index1+i,s2,index2+i,len-i) )
					return true;
				if( isScramble(s1,index1,s2,index2+len-i,i) && isScramble(s1,index1+i,s2,index2,len-i) )
					return true;
			}
			return false;
	}
};
