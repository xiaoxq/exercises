/*
 * Problem: http://leetcode.com/onlinejudge#question_104
 */

#include <stack>
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
	int maxDepth(TreeNode *root)
	{
		int result = 0;
		if( root==NULL )
			return result;

		queue<TreeNode*> toVisit;
		toVisit.push( root );
		toVisit.push( NULL );
		while( true )
		{
			TreeNode *cur = toVisit.front(); toVisit.pop();
			// end a level
			if( cur==NULL )
			{
				++result;
				if( toVisit.empty() )
					break;
				// add a new End-Of-Level
				toVisit.push( NULL );
			}
			else
			{
				if( cur->left )
					toVisit.push( cur->left );
				if( cur->right )
					toVisit.push( cur->right );
			}
		}
		return result;
	}
};
