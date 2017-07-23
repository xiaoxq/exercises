/*
 * Problem: http://leetcode.com/onlinejudge#question_65
 */

#define NULL 0

class Solution
{
public:
	bool isNumber(const char *s)
	{
		// "[ ][+|-][ ]int/float[epart3][ ]"
		int part = 1;

		s = skipWhite(s);
		if( *s=='+' | *s=='-' )
			++s;
		if( (s=readIntOrFloat(s))==NULL )
			return false;
		if( *s=='e' )
		{
			++s;
			if( *s=='+' | *s=='-' )
				++s;
			if( (s = readInt(s))==NULL )
				return false;
		}
		s = skipWhite(s);
		return ( *s==0 );
	}
private:
	const char* readIntOrFloat(const char *s)
	{
		bool meetDot = false, hasReadSome = false;
		while( true )
		{
			if( *s=='.' )
			{
				if( meetDot )
					return NULL;
				meetDot = true;
			}
			else if( *s<'0' || *s>'9' )
				break;
			else
				hasReadSome = true;
			++s;
		}
		return hasReadSome ? s : NULL;
	}

	const char* readInt(const char *s)
	{
		bool hasReadSome = false;
		while( *s>='0' && *s<='9' )
		{
			hasReadSome = true;
			++s;
		}
		return hasReadSome ? s : NULL;
	}

	const char* skipWhite(const char *s)
	{
		while( isspace(*s) )
			++s;
		return s;
	}
};
