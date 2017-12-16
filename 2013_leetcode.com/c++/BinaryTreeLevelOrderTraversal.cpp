/*
 * Problem: http://leetcode.com/onlinejudge#question_102
 */

#include <vector>
#include <queue>
using namespace std;

#define NULL 0

// Definition for binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<vector<int> > levelOrder(TreeNode *root)
	{
		vector<vector<int> > result;
		if( root==NULL )
			return result;

		vector<int> level;
		queue<TreeNode*> toVisit;
		toVisit.push( root );
		toVisit.push( NULL );
		while( true )
		{
			TreeNode *cur = toVisit.front(); toVisit.pop();
			// end a level
			if( cur==NULL )
			{
				result.push_back( level );
				if( toVisit.empty() )
					break;
				// add a new End-Of-Level
				level.clear();
				toVisit.push( NULL );
			}
			else
			{
				level.push_back( cur->val );
				if( cur->left )
					toVisit.push( cur->left );
				if( cur->right )
					toVisit.push( cur->right );
			}
		}
		return result;
	}
};
