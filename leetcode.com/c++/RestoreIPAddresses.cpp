/*
 * Problem: http://leetcode.com/onlinejudge#question_93
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> result;
		vector<int> preDots;
		genIp( s, 0, preDots, result );
		return result;
	}
private:
	// prePartsNum = 0|1|2|3|4
	void genIp(const string& s, int index, vector<int>& preDots, vector<string>& result )
	{
		const int len = s.length();
		int remainPartsNum = 4 - preDots.size();
		// too long remain
		if( index + remainPartsNum * 3 < len )
			return;
		// too short remain
		if( index + remainPartsNum > len )
			return;

		if( remainPartsNum == 1 )
		{
			// no leading 0s
			if( s[index]=='0' && s[index+1]!=0 )
				return;

			// find a valid ip
			if( atoi( s.c_str() + index )<=255 )
			{
				string solution(s);
				solution.insert( preDots[0], 1, '.' );
				solution.insert( preDots[1]+1, 1, '.' );
				solution.insert( preDots[2]+2, 1, '.' );
				result.push_back( solution );
			}
			return;
		}

		// try read one digit
		if( s[index]=='0' )
		{
			preDots.push_back( index+1 );
			genIp( s, index+1, preDots, result );
			preDots.pop_back();
		}
		// try read 1~3 digit
		else
		{
			int part = 0;
			for( int i=0; i<3 && index+i<len; ++i )
			{
				part = 10*part + s[index+i]-'0';
				if( part>255 )
					break;
				preDots.push_back( index+i+1 );
				genIp( s, index+i+1, preDots, result );
				preDots.pop_back();
			}
		}
	}
};
