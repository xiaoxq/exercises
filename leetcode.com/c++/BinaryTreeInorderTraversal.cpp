/*
 * Problem: http://leetcode.com/onlinejudge#question_94
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
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		// to all nodes in the stack, themselves and the right
		// children havn't been visited
		stack<TreeNode*> parents;
		while( root!=NULL )
		{
			if( root->left )
			{
				parents.push( root );
				root = root->left;
			}
			else
			{
				result.push_back( root->val );
				if( root->right )
					root = root->right;
				else
				{
					while( root->right == NULL )
					{
						if( parents.empty() )
							return result;
						root = parents.top();
						parents.pop();
						result.push_back( root->val );
					}
					root = root->right;
				}
			}
		}
		return result;
	}
};
