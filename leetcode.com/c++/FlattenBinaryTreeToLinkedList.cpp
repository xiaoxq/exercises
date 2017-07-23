/*
 * Problem: http://leetcode.com/onlinejudge#question_114
 */

#include <stack>
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
	void flatten(TreeNode *root)
	{
		stack<TreeNode *> rights;
		while( root!=NULL )
		{
			if( root->left==NULL )
			{
				if( root->right==NULL )
				{
					if( rights.empty() )
						break;
					root->right = rights.top(); rights.pop();
				}
			}
			else
			{
				if( root->right )
					rights.push( root->right );
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
};
