/*
 * Problem: http://leetcode.com/onlinejudge#question_58
 */

#define NULL 0

class Solution
{
public:
	int lengthOfLastWord(const char *s)
	{
		if( s==NULL )
			return 0;

		const char* startPos = NULL, *endPos = NULL;
		while( s[0] != 0 )
		{
			if( startPos==NULL && s[0]!=' ' )
				startPos = s+1;

			if( s[0]==' ' && s[1]!=' ' && s[1]!= 0 )
				startPos = s;
			else if( s[0]!=' ' && s[1]==' ' )
				endPos = s+1;

			++s;
		}
		if( endPos<startPos )
			endPos = s;
		return endPos - startPos;
	}
};
