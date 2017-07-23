/*
 * Problem: http://leetcode.com/onlinejudge#question_99
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
	void recoverTree(TreeNode *root)
	{
		if(root == NULL)
			return;

		TreeNode *f1=NULL, *f2=NULL;
		bool found = false;
		TreeNode *cur=root, *parent=NULL;
		while( cur )
		{
			if( cur->left == NULL )
			{
				if(parent && parent->val > cur->val)
				{
					if(!found)
					{
						f1 = parent;
						found = true;
					}
					f2 = cur;
				}
				parent = cur;
				cur = cur->right;
			}
			else
			{
				// Find the inorder predecessor of current
				TreeNode *pre = cur->left;
				while(pre->right != NULL && pre->right != cur)
					pre = pre->right;

				// Make current as right child of its inorder predecessor
				if(pre->right == NULL)
				{
					pre->right = cur;
					cur = cur->left;
				}
				else
				{
					// Revert the changes made in if part to restore the original tree
					pre->right = NULL;
					if(parent->val > cur->val)
					{
						if(!found)
						{
							f1 = parent;
							found = true;
						}
						f2 = cur;
					}
					parent = cur;
					cur = cur->right;
				}
			}
		}
		if(f1 && f2)
		{
			int temp = f1->val;
			f1->val = f2->val;
			f2->val = temp;
		}
	}
};
