/*
 * Problem: http://leetcode.com/onlinejudge#question_105
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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		return buildTree( preorder, 0, inorder, 0, preorder.size() );
	}
private:
	// For tree A->(B,C), preorder says ABC, inorder says BAC
	TreeNode *buildTree(vector<int> &preorder, int preIndex,
			vector<int> &inorder, int inIndex, int size)
	{
		if( size==0 )
			return NULL;
		// decode A
		TreeNode *root = new TreeNode( preorder[preIndex] );
		// find A in inorder
		int lenB=0;
		while( inorder[inIndex+lenB] != preorder[preIndex] )
			++lenB;
		// decode B, C
		root->left = buildTree( preorder, preIndex+1, inorder, inIndex, lenB );
		root->right = buildTree( preorder, preIndex+1+lenB, inorder, inIndex+1+lenB, size-1-lenB );
		return root;
	}
};
