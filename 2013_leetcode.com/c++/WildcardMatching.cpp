/*
 * Problem: http://leetcode.com/onlinejudge#question_44
 */

#include <vector>
#include <string.h>
#include <string>
using namespace std;

class Solution
{
public:
	bool isMatch(const char *s, const char *p)
	{
		const int lenS = strlen(s);
		const int lenP = strlen(p);
		int indexP=0;
		int lastStarPosInP=-1;
		int lastStarPosInS=0;

		for( int indexS=0; indexS<lenS; )
		{
			//one * and multiple *, same effect
			while(indexP<lenP && p[indexP]=='*')
			{
				lastStarPosInS = indexS;
				lastStarPosInP = indexP++; // initially match 0 character
			}

			// not match
			if(indexP==lenP || (p[indexP]!=s[indexS] && p[indexP]!='?'))
			{
				if(lastStarPosInP<0)
					return false;
				indexP = lastStarPosInP+1;
				indexS = ++lastStarPosInS; // match 1 more character
			}
			else
			{
				++indexS;
				++indexP;
			}
		}

		while(indexP<lenP && p[indexP]=='*')
			++indexP;
		return indexP==lenP;
	}
};
