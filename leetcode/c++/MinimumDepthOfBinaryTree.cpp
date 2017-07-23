/*
 * Problem: http://leetcode.com/onlinejudge#question_111
 */

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
	int minDepth(TreeNode *root)
	{
		if( root==NULL )
			return 0;
		queue<TreeNode *> toVisit;
		toVisit.push( root );
		toVisit.push( NULL );
		int level = 1;
		while( true )
		{
			TreeNode* cur = toVisit.front(); toVisit.pop();
			if( cur==NULL )
			{
				++level;
				toVisit.push( NULL );
			}
			else
			{
				if( cur->left==NULL && cur->right==NULL )
					return level;
				if( cur->left )
					toVisit.push( cur->left );
				if( cur->right )
					toVisit.push( cur->right );
			}
		}
		return level;
	}
};
