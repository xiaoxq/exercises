/*
 * Problem: http://leetcode.com/onlinejudge#question_21
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode *head = NULL, *tail = NULL;
		while( l1!=NULL && l2!=NULL )
		{
			ListNode *next;
			if( l1->val < l2->val )
			{
				next = l1;
				l1 = l1->next;
			}
			else
			{
				next = l2;
				l2 = l2->next;
			}

			if( tail==NULL )
			{
				head = tail = next;
			}
			else
			{
				tail->next = next;
				tail = next;
			}
		}
		if( tail!=NULL )
			tail->next = ( l1==NULL ) ? l2 : l1;
		else
			head = ( l1==NULL ) ? l2 : l1;
		return head;
	}
};
