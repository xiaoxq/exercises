/*
 * Problem: http://leetcode.com/onlinejudge#question_83
 */

#define NULL 0

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if( head==NULL )
			return NULL;

		ListNode *tail = head;
		while( tail->next!=NULL )
		{
			if( tail->next->val != tail->val )
				tail = tail->next;
			else
				tail->next = tail->next->next;
		}

		return head;
	}
};
