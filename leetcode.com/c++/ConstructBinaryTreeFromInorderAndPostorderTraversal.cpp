/*
 * Problem: http://leetcode.com/onlinejudge#question_106
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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		return buildTree( inorder, 0, postorder, 0, inorder.size() );
	}
private:
	// For tree A->(B,C), inorder says BAC, postorder says BCA
	TreeNode *buildTree(vector<int> &inorder, int inIndex,
			vector<int> &postorder, int postIndex, int size)
	{
		if( size==0 )
			return NULL;
		// decode A
		int A = postorder[postIndex+size-1];
		TreeNode *root = new TreeNode( A );
		// find A in inorder
		int lenB=0;
		while( inorder[inIndex+lenB] != A )
			++lenB;
		// decode B, C
		root->left = buildTree( inorder, inIndex, postorder, postIndex, lenB );
		root->right = buildTree( inorder, inIndex+1+lenB, postorder, postIndex+lenB, size-1-lenB );
		return root;
	}
};
