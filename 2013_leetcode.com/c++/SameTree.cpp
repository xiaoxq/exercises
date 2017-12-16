/*
 * Problem: http://leetcode.com/onlinejudge#question_100
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
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		// the same node or both NULL
		if( p==q )
			return true;
		// only one is NULL, or not equal
		if( p==NULL || q==NULL || p->val!=q->val )
			return false;
		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	}
};
