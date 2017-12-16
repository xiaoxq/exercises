/*
 * Problem: http://leetcode.com/onlinejudge#question_67
 */

#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int len = max( a.length(), b.length() ) + 1;
		string result( len, '0' );

		string::const_reverse_iterator ita = a.rbegin(), itb = b.rbegin();

		int carry=0;
		while( ita!=a.rend() || itb!=b.rend() )
		{
			if( ita!=a.rend() )
			{
				carry += *ita - '0';
				++ita;
			}
			if( itb!=b.rend() )
			{
				carry += *itb - '0';
				++itb;
			}
			result[--len] += carry & 0x1;
			carry >>= 1;
		}
		if( carry )
			result[0] += 1;
		else
			result.erase( 0, 1 );

		return result;
	}
};
