/*
 * Problem: http://leetcode.com/onlinejudge#question_116
 */

#define NULL 0

// Definition for binary tree with next pointer.
struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		while( root!=NULL )
		{
			// connect one level and return the head of next level
			TreeLinkNode* nextLevel = root->left;
			while( root!=NULL )
			{
				TreeLinkNode *left=root->left, *right=root->right;
				while( left!=NULL )
				{
					left->next = right;
					left = left->right;
					right = right->left;
				}
				root = root->next;
			}
			root = nextLevel;
		}
	}
};
