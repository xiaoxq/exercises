/*
 * Problem: http://leetcode.com/onlinejudge#question_110
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
	bool isBalanced(TreeNode *root)
	{
		return (getDepthIfBalanced(root) != -1);
	}
private:
	int getDepthIfBalanced( TreeNode *root )
	{
		if( root==NULL )
			return 0;
		int left = getDepthIfBalanced( root->left );
		int right = getDepthIfBalanced( root->right );
		if( left==-1 || right==-1 || left-right>1 || left-right<-1 )
			return -1;
		return left>right ? left+1 : right+1;
	}
};
