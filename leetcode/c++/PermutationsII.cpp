/*
 * Problem: http://leetcode.com/onlinejudge#question_47
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int> > permuteUnique(vector<int> &num)
	{
		vector<vector<int> > result;
		if( num.empty() )
			return result;

		getPermutations( num, 0, result );
		return result;
	}
private:
	void getPermutations( const vector<int> &num, int index, vector<vector<int> >& permutations )
	{
		if( index+1 == num.size() )
		{
			vector<int> permutation( 1, num[index] );
			permutations.push_back( permutation );
		}
		else if( index < num.size() )
		{
			// get the sub-permutations
			vector<vector<int> > sub_permutations;
			getPermutations( num, index+1, sub_permutations );

			// insert the picked num[0] to every position of sub-permutations
			for( vector<vector<int> >::iterator sub_it=sub_permutations.begin();
					sub_it!=sub_permutations.end(); ++sub_it )
			{
				for( int j=0; j<=sub_it->size(); ++j )
				{
					// The only difference with Permutations: Skip when a duplicate number is in ahead
					if( j>0 && (*sub_it)[j-1]==num[index] )
						break;

					vector<int> permutation( *sub_it );
					permutation.insert( permutation.begin()+j, num[index] );
					permutations.push_back(permutation);
				}
			}
		}
	}
};

