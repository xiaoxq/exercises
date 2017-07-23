/*
 * Problem: http://leetcode.com/onlinejudge#question_60
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		if(n==1)
			return "1";

		vector<bool> used(n, false);
		// changeInfluence[n-i-1]=i!
		// to 123, if you change 1 to 2, that means the tail has changed 2! times
		vector<int> changeInfluence(n-1, 1);
		for( int i=2; i<n; ++i )
		{
			changeInfluence[n-i-1] = i * changeInfluence[n-i];
		}

		string result( n );
		for( int i=0; i+1<n; ++i )
		{
			int chooseXthMin = (k-1) / changeInfluence[i];
			k -= chooseXthMin * changeInfluence[i];
			for( int j=0; j<n; ++j )
			{
				if( !used[j] )
				{
					if( chooseXthMin==0 )
					{
						result[i] = '1' + j;
						used[j] = true;
						break;
					}
					--chooseXthMin;
				}
			}
		}
		// decide the last one
		for( int i=0; i<n; ++i )
		{
			if( !used[i] )
			{
				result[n-1] = '1' + i;
				break;
			}
		}
		return result;
	}
};
