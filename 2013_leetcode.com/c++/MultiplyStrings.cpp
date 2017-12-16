/*
 * Problem: http://leetcode.com/onlinejudge#question_43
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		vector<string> components;
		string result( num1.length() + num2.length() );
		int carry = 0, writePos = result.length();

		for( string::const_reverse_iterator it=num2.rbegin(); it!=num2.rend(); ++it )
		{
			string component = mulStringWithOneDigit( num1, *it - '0' );
			components.push_back( component );
			int sum = addOneDigitInStrings( components, carry );
			result[--writePos] = (sum%10) + '0';
			carry = sum / 10;
		}
		while( !components.empty() )
		{
			int sum = addOneDigitInStrings( components, carry );
			result[--writePos] = (sum%10) + '0';
			carry = sum / 10;
		}
		if( carry>0 )
			result[--writePos] = carry + '0';

		// remove leading 0s
		while( result[writePos]=='0' && writePos+1 < result.length() )
			++writePos;
		if( writePos>0 )
			result.erase( 0, writePos );

		return result;
	}
private:
	// digit is in [0,9], and return the result in reverse order of number
	string mulStringWithOneDigit( const string& num, int digit )
	{
		string result( num.length()+1 );

		int carry = 0, writePos = 0;
		for( string::const_reverse_iterator it=num.rbegin(); it!=num.rend(); ++it )
		{
			int sum = (*it - '0') * digit + carry;
			result[writePos++] = (sum % 10) + '0';
			carry = sum / 10;
		}
		result[ writePos ] = carry + '0';
		return result;
	}

	int addOneDigitInStrings( vector<string>& components, int carry )
	{
		for( vector<string>::iterator it=components.begin(); it!=components.end(); )
		{
			string& num = *it;
			carry += num[0] - '0';
			num.erase( 0, 1 );
			if( num.empty() )
				it = components.erase( it );
			else
				++it;
		}
		return carry;
	}
};
