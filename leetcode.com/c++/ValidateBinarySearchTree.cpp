/*
 * Problem: http://leetcode.com/onlinejudge#question_98
 */

#include <limits.h>

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
	bool isValidBST(TreeNode *root)
	{
		int lastVal = INT_MIN;
		return isValidBST(root, lastVal);
	}
private:
	bool isValidBST(TreeNode *root, int& lastVal)
	{
		if( root==NULL )
			return true;

		if( !isValidBST(root->left, lastVal) )
			return false;

		if( lastVal >= root->val )
			return false;
		lastVal = root->val;

		return isValidBST(root->right, lastVal);
	}
};
