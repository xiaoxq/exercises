/*
 * Problem: http://leetcode.com/onlinejudge#question_24
 */

#ifndef NULL
#define NULL 0
#endif

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
	ListNode *swapPairs(ListNode *head)
	{
		if( head==NULL || head->next==NULL )
			return head;

		// swap head and head->next
		ListNode *n1=head, *n2=n1->next;
		head = n2;
		n1->next = n2->next;
		n2->next = n1;

		n1=head->next;
		n2=n1->next;

		while( n2!=NULL && n2->next!=NULL )
		{
			// n1->n2->n3->... to n1->n3->n2->...
			ListNode *n3 = n2->next;
			n2->next = n3->next;
			n3->next = n2;
			n1->next = n3;
			n1 = n2;
			n2 = n1->next;
		}
		return head;
	}
};

