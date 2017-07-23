/*
 * Problem: http://leetcode.com/onlinejudge#question_2
 */

// Definition for singly-linked list.
#define NULL 0
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *head = NULL, *tail = NULL;
		int carry = 0;

		while( l1!=NULL || l2!=NULL )
		{
			int num1 = (l1!=NULL) ? l1->val : 0;
			int num2 = (l2!=NULL) ? l2->val : 0;
			int sum = num1 + num2 + carry;
			carry = sum/10;
			sum %= 10;

			// initial
			if( tail==NULL )
			{
				head = tail = new ListNode( sum );
			}
			// generally
			else
			{
				tail->next = new ListNode( sum );
				tail = tail->next;
			}

			if(l1!=NULL)
				l1 = l1->next;
			if(l2!=NULL)
				l2 = l2->next;
		}

		// the final carry
		if( carry>0 )
			tail->next = new ListNode( carry );

		return head;
	}
};
