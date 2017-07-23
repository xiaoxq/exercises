/*
 * Problem: http://leetcode.com/onlinejudge#question_108
 */

#include <vector>
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
	TreeNode *sortedArrayToBST(vector<int> &num)
	{
		return sortedArrayToBST( num, 0, num.size() );
	}
private:
	TreeNode *sortedArrayToBST(vector<int> &num, int left, int right)
	{
		if( left==right )
			return NULL;
		int middle = (left+right) / 2;
		TreeNode *root = new TreeNode( num[middle] );
		root->left = sortedArrayToBST( num, left, middle );
		root->right = sortedArrayToBST( num, middle+1, right );
		return root;
	}
};
