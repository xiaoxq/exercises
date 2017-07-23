/*
 * Problem: http://leetcode.com/onlinejudge#question_124
 */

#include <algorithm>
using namespace std;

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
	int maxPathSum(TreeNode *root)
	{
		if( root==NULL )
			return 0;
		int result = root->val;
		int sumWithRoot = maxPathSum( root, result );
		return max( sumWithRoot, result );
	}
private:
	int maxPathSum(TreeNode *root, int& result)
	{
		// return a mini number, make sure it <= result
		if( root==NULL )
			return result < 0 ? result : -1;

		const int left = maxPathSum(root->left, result);
		const int right = maxPathSum(root->right, result);

		const int maxiChild = max( left, right );
		const int withRoot = left + right + root->val;
		result = max( result, max(maxiChild,withRoot) );

		if( left<=0 && right<=0 )
			return root->val;
		return maxiChild+root->val;
	}
};
