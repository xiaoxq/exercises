/*
 * Problem: http://leetcode.com/onlinejudge#question_117
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
		while( root )
		{
			TreeLinkNode *nextLevel = NULL;

			// connect one level
			while( root )
			{
				// assign the next level head
				if( nextLevel==NULL )
					nextLevel = (root->left) ? root->left : root->right;

				// connect my children
				if( root->left && root->right )
					root->left->next = root->right;
				// find my rightest child
				TreeLinkNode *myRightestChild = (root->right) ? root->right : root->left;
				// find the brother of my rightest child
				if( myRightestChild )
				{
					TreeLinkNode *myRightestChildNext = NULL;

					TreeLinkNode *brother = root->next;
					while( brother )
					{
						if( brother->left )
						{
							myRightestChildNext = brother->left;
							break;
						}
						else if( brother->right )
						{
							myRightestChildNext = brother->right;
							break;
						}
						brother = brother->next;
					}
					myRightestChild->next = myRightestChildNext;
				}

				root = root->next;
			}

			root = nextLevel;
		}
	}
};
