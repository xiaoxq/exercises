/*
 * Problem: http://leetcode.com/onlinejudge#question_28
 */

#include <vector>
using namespace std;

#define NULL 0

class Solution
{
public:
	char *strStr(char *haystack, char *needle)
	{
		// special cases
		if(haystack == NULL || needle == NULL)
			return NULL;
		int hlen = strlen(haystack), nlen = strlen(needle);
		if(hlen == 0 ) return NULL;
		if(nlen == 0 ) return haystack;

		// gen pattern
		vector<int> pattern(nlen);
		genPattern(needle, nlen, pattern);

		// match
		int k = -1;
		char* result = NULL;
		for(int j=0; j<hlen; ++j, ++haystack)
		{
			while(k >-1 && needle[k+1] != *haystack)
				k = pattern[k];
			if(needle[k+1] == *haystack)
				k++;
			if(k == nlen-1)
			{
				result = haystack-k;
				break;
			}
		}
		return result;
	}

private:
	void genPattern(char* str, int len, vector<int>& pattern)
	{
		pattern[0] = -1;
		int k =-1;
		for(int j=1; j<len; ++j)
		{
			while(k >-1 && str[k+1] != str[j])
				k = pattern[k];
			if(str[k+1] == str[j])
				k++;
			pattern[j] = k;
		}
	}
};
