/*
 * Problem: http://leetcode.com/onlinejudge#question_112
 */

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
	bool hasPathSum(TreeNode *root, int sum)
	{
		if( root==NULL )
			return false;
		sum -= root->val;
		if( sum==0 && root->left==NULL && root->right==NULL )
			return true;
		return hasPathSum( root->left, sum ) || hasPathSum( root->right, sum );
	}
};
