/*
 * Problem: http://leetcode.com/onlinejudge#question_109
 */

#include <vector>
using namespace std;

#define NULL 0

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	TreeNode *sortedListToBST(ListNode *head)
	{
		ListNode *cur = head;
		int len=0;
		while( cur != NULL )
		{
			cur = cur->next;
			++ len;
		}
		return sortedListToBST( head, len );
	}
private:
	TreeNode *sortedListToBST(ListNode *head, const int len)
	{
		if(len==0)
			return NULL;
		ListNode *cur = head;
		for( int i=0; i<len/2; ++i )
			cur = cur->next;

		TreeNode *root = new TreeNode( cur->val );
		root->left = sortedListToBST( head, len/2 );
		root->right = sortedListToBST( cur->next, (len-1)/2 );
		return root;
	}
};
