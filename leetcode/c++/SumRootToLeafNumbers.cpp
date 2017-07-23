/*
 * Problem: http://leetcode.com/onlinejudge#question_129
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
	int sumNumbers(TreeNode *root)
	{
		return sumNumbers( root, 0 );
	}
private:
	int sumNumbers(TreeNode *root, int parent)
	{
		if( root==NULL )
			return 0;

		parent = parent*10 + root->val;
		if( root->left==NULL && root->right==NULL )
			return parent;

		return sumNumbers( root->left, parent ) + sumNumbers( root->right, parent );
	}
};
