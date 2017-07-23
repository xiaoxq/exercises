/*
 * Problem: http://leetcode.com/onlinejudge#question_76
 */

#include <string>
#include <limits.h>
#include <map>
using namespace std;

class Solution
{
public:
	// assume that T has no duplicate chars
	string minWindow(string S, string T)
	{
		const int lenS = S.length();
		const int lenT = T.length();
		if( lenS==0 || lenT==0 )
			return "";

		// init
		map<char,int> shouldShowupCount;
		map<char,int> showupCount;
		for( int i=0; i<lenT; ++i )
		{
			map<char,int>::iterator it = shouldShowupCount.find( T[i] );
			if( it == shouldShowupCount.end() )
			{
				shouldShowupCount.insert( make_pair( T[i], 1 ) );
				showupCount.insert( make_pair( T[i], 0 ) );
			} else
				++ it->second;
		}

		int left=0, right=0;
		if( !findFirstWindow(S,left,right,shouldShowupCount,showupCount) )
			return "";

		int minWindowStart=left, minWindowLen=right-left;
		while( right < lenS  )
		{
			// move right to the first S[left]
			if( S[right] != S[left] )
			{
				map<char,int>::iterator it = showupCount.find( S[right] );
				if( it!=showupCount.end() )
					++ it->second;
				++ right;
				continue;
			}
			++ right;

			// move left to its position
			for( ++left; left<right; ++left )
			{
				map<char,int>::iterator it = showupCount.find( S[left] );
				if( it==showupCount.end() )
					continue;
				if( it->second == shouldShowupCount[ S[left] ] )
					break;
				-- it->second;
			}
			if( right-left < minWindowLen )
			{
				minWindowStart = left;
				minWindowLen = right-left;
			}
		}
		return S.substr( minWindowStart, minWindowLen );
	}
private:
	//let S[left,right] contains T
	bool findFirstWindow( const string& S, int& left, int& right,
			map<char,int>& shouldShowupCount, map<char,int>& showupCount )
	{
		const int lenS = S.length();

		// move right to its position
		int shownUp = 0;
		while( shownUp<shouldShowupCount.size() && right<lenS )
		{
			map<char,int>::iterator it = showupCount.find( S[right] );
			if( it!=showupCount.end() )
			{
				++ it->second;
				if( it->second == shouldShowupCount[ S[right] ] )
					++shownUp;
			}
			++right;
		}
		// no such window
		if( shownUp < shouldShowupCount.size() )
			return false;

		// move left to its position
		for( ; left<right; ++left )
		{
			map<char,int>::iterator it = showupCount.find( S[left] );
			if( it==showupCount.end() )
				continue;
			if( it->second == shouldShowupCount[ S[left] ] )
				break;
			-- it->second;
		}
		return true;
	}
};
